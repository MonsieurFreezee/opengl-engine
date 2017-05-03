#include "obj_loader.h"
#include "string_utils.h"
#include <fstream>
#include <stdexcept>
#include "io_utils.h"
#include <map>
#include <iostream>
#include <cstdint>

void load_OBJ(const std::string &location, std::vector<GLfloat> &vertices, std::vector<GLuint> &indices)
{
    // We clear to be sure that nothing wasn't already putted in
    vertices.clear();
    indices.clear();

    std::string file_content;
    std::ifstream file_stream{location, std::ios::in};

    if (!file_stream.is_open())
    {
        throw unknown_file(location);
    }

    std::vector<GLfloat> vertices_list;
    std::vector<GLfloat> texture_coords_list;

    std::map<std::string, GLuint> indices_map;
    std::map<std::string, GLuint>::iterator it;

    std::string line {""};
    uint64_t line_count {0};
    uint64_t indices_count {0};
    while (!file_stream.eof())
    {
        std::getline(file_stream, line);
        ++line_count;
        if (line[0] == 'f' || line[0] == 'v')
        {
            std::vector<std::string> split_line {split(line, ' ')};

            if (split_line[0][1] == 't')
            {
                if (split_line.size() != 3) throw std::invalid_argument{location + " line " + std::to_string(line_count) + ": " + std::to_string(split_line.size() - 1) + " texture coordinates arguments instead of 2"};
                for (uint8_t i{1}; i <= 2; ++i) texture_coords_list.push_back(std::stof(split_line[i]));
            }
            else if (split_line[0][0] == 'v')
            {
                if (split_line.size() != 4) throw std::invalid_argument{location + " line " + std::to_string(line_count) + ": " + std::to_string(split_line.size() - 1) + " vertices arguments instead of 3"};
                for (uint8_t i{1}; i <= 3; ++i) vertices_list.push_back(std::stof(split_line[i]));
            }
            else if (split_line[0][0] == 'f')
            {
                for (uint8_t i{1}; i <= 3; ++i)
                {
                    it = indices_map.find(std::string(split_line[i]));
                    if (it != indices_map.end())
                    {
                        indices.push_back(it->second);
                    }
                    else
                    {
                        std::vector<std::string> subsplit {split(split_line[i], '/')};

                        try
                        {
                            uint16_t toi1{static_cast<uint16_t>(std::stoi(subsplit[0]))};
                            uint16_t toi2{static_cast<uint16_t>(std::stoi(subsplit[1]))};
                            for (uint8_t j{0}; j < 3; ++j) vertices.push_back(vertices_list[(toi1-1)*3+j]);
                            for (uint8_t j{0}; j < 2; ++j) vertices.push_back(texture_coords_list[(toi2-1)*2+j]);
                        }
                        catch (const std::invalid_argument &exception)
                        {
                            throw std::invalid_argument{location + " line " + std::to_string(line_count) + ": Incorrect integer value (" + split_line[i] + ")"};
                        }

                        indices_map[split_line[i]] = static_cast<GLuint>(indices_count);
                        indices.push_back(indices_count++);
                    }
                }
            }
        }
    }
}

Mesh load_mesh(const std::string &location)
{
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
    load_OBJ(location, vertices, indices);

    return {Mesh{vertices, indices}};
}

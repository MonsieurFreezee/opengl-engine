#include "shader.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

Shader::Shader(const std::string &location, GLenum shader_type):
    m_shader_ID {glCreateShader(shader_type)},
    m_shader_type {shader_type}
{
    std::string shader_content;
    std::ifstream file_stream {location, std::ios::in};

    if (!file_stream.is_open())
    {
        std::cerr << "Could not read file " << location << ". File does not exist.\n";
        exit(-1);
    }

    std::string line {""};
    while (!file_stream.eof())
    {
        std::getline(file_stream, line);
        shader_content.append(line + "\n");
    }

    file_stream.close();

    const char *content {shader_content.c_str()};

    glShaderSource(m_shader_ID, 1, &content, nullptr);
    glCompileShader(m_shader_ID);

    // Checks for error
    GLint success;
    glGetShaderiv(m_shader_ID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        // Fancy way to optimize memory: query the length with GL_INFO_LOG_LENGTH
        GLint length;
        glGetShaderiv(m_shader_ID, GL_INFO_LOG_LENGTH, &length);
        GLchar log[length];
        glGetShaderInfoLog(m_shader_ID, length, nullptr, log);
        std::cerr << "Error while compiling the shader (" << location << "): " << log << '\n';
        exit(-1);
    }
}

Shader::~Shader()
{
    glDeleteShader(m_shader_ID);
}

GLenum Shader::get_shader_type() const
{
    return {m_shader_type};
}

GLuint Shader::get_shader_ID() const
{
    return {m_shader_ID};
}

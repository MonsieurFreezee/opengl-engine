#pragma once
#include <GL/glew.h>
#include <cstdint>
#include <vector>

class Mesh
{
private:
    const GLuint m_VAO;
    const GLuint m_VBO;
    const GLuint m_EBO=0;
    const uint16_t m_vertex_count;

    GLuint create_VAO_ID() const;
    GLuint create_buffer_object_ID() const;

public:
    Mesh(const std::vector<GLfloat> &vertices);
    Mesh(const std::vector<GLfloat> &vertices, const std::vector<GLuint> &indices);

    GLuint get_VAO() const;
    GLuint get_VBO() const;
    GLuint get_EBO() const;
    uint16_t get_vertex_count() const;
};

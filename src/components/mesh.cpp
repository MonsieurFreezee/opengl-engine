#include "mesh.h"
#include "obj_loader.h"
#include <iostream>

GLuint Mesh::create_VAO_ID() const
{
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    return {VAO};
}

GLuint Mesh::create_buffer_object_ID() const
{
    GLuint BO;
    glGenBuffers(1, &BO);
    return {BO};
}

Mesh::Mesh(const std::vector<GLfloat> &vertices):
    m_VAO {create_VAO_ID()},
    m_VBO {create_buffer_object_ID()},
    m_vertex_count {static_cast<uint16_t>(vertices.size() / 3)}
{
    glBindVertexArray(m_VAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0));
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

Mesh::Mesh(const std::vector<GLfloat> &vertices, const std::vector<GLuint> &indices):
    m_VAO {create_VAO_ID()},
    m_VBO {create_buffer_object_ID()},
    m_EBO {create_buffer_object_ID()},
    m_vertex_count {static_cast<uint16_t>(indices.size())}
{
    glBindVertexArray(m_VAO);
        // VBO (vertices)
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

        // EBO (indices)
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0));
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

GLuint Mesh::get_VAO() const
{
    return {m_VAO};
}

GLuint Mesh::get_VBO() const
{
    return {m_VBO};
}

GLuint Mesh::get_EBO() const
{
    return {m_EBO};
}

uint16_t Mesh::get_vertex_count() const
{
    return {m_vertex_count};
}

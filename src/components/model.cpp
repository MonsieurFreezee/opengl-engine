#include "model.h"
#include <iostream>

Model::Model(const Mesh &mesh, const Texture &texture):
    m_mesh {mesh},
    m_texture {texture}
{

}

void Model::render(const ShaderProgram &shader_program) const
{
    (void) shader_program;
    m_texture.bind();
    glBindVertexArray(m_mesh.get_VAO());
    if (!m_mesh.get_EBO())
    {
        glDrawArrays(GL_TRIANGLES, 0, m_mesh.get_vertex_count());
    }
    else
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_mesh.get_EBO());
        glDrawElements(GL_TRIANGLES, m_mesh.get_vertex_count(), GL_UNSIGNED_INT, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    glBindVertexArray(0);
    Texture::bind(0);
}

#include "render.h"
#include "updateable.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Render::Render(const ShaderProgram &shader_program, const Camera &camera):
    m_program {shader_program},
    m_camera {camera}
{

}

void Render::render()
{
    if (m_has_program_changed)
    {
        m_program.use();
        m_has_program_changed = false;
    }

    // Update camera position (view matrix)
    glm::mat4 view;
    view = glm::translate(view, glm::vec3(m_camera.get_position_X(),
                                          m_camera.get_position_Y(),
                                          m_camera.get_position_Z()));
    view = glm::rotate(view, glm::radians(m_camera.get_rotation_X()), glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::rotate(view, glm::radians(m_camera.get_rotation_Y()), glm::vec3(0.0f, 1.0f, 0.0f));
    view = glm::rotate(view, glm::radians(m_camera.get_rotation_Z()), glm::vec3(0.0f, 0.0f, 1.0f));
    GLint view_loc = glGetUniformLocation(m_program.get_ID(), "view");
    glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));

    // Update projection (projection matrix)
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(90.0f), 1280.0f / 720.0f, 0.1f, 100.0f);
    GLint projection_loc = glGetUniformLocation(m_program.get_ID(), "projection");
    glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection));

    for (const auto &to_render: m_to_render)
    {
        if (dynamic_cast<Updateable*>(&(*to_render)) != nullptr)
        {
            Updateable *to_update{dynamic_cast<Updateable*>(&(*to_render))};
            to_update->update();
        }
        to_render->render(m_program);
    }
}

const std::vector<std::shared_ptr<Renderable>>& Render::get_render_list() const
{
    return {m_to_render};
}

const ShaderProgram& Render::get_shader_program() const
{
    return {m_program};
}

const Camera& Render::get_camera() const
{
    return {m_camera};
}

void Render::add(Renderable *to_add)
{
    m_to_render.push_back(std::shared_ptr<Renderable>(to_add));
}

void Render::set_shader_program(ShaderProgram &shader_program)
{
    m_program = shader_program;
    m_has_program_changed = true;
}

void Render::set_camera(const Camera &camera){
    m_camera = camera;
}

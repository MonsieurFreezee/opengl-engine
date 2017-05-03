#pragma once
#include <vector>
#include "renderable.h"
#include "shader_program.h"
#include "camera.h"
#include <memory>

class Render
{
private:
    std::vector<std::shared_ptr<Renderable>> m_to_render;
    ShaderProgram m_program;
    Camera m_camera;
    bool m_has_program_changed=false;

public:
    Render(const ShaderProgram &shader_program, const Camera &camera);

    void render();

    const std::vector<std::shared_ptr<Renderable>>& get_render_list() const;
    const ShaderProgram& get_shader_program() const;
    const Camera& get_camera() const;

    void add(Renderable *to_add);
    void set_shader_program(ShaderProgram &shader_program);
    void set_camera(const Camera &camera);
};

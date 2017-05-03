#pragma once
#include <GL/glew.h>
#include "shader.h"

class ShaderProgram
{
private:
    GLuint m_shader_program_ID;

    void compile_shaders(const Shader &vertex_shader, const Shader &fragment_shader) const;

public:
    ShaderProgram(Shader &vertex_shader, Shader &fragment_shader);
    ShaderProgram(const std::string &vertex_shader_location, const std::string &fragment_shader_location);

    GLuint get_ID() const;

    void use() const;
    static void use(GLuint shader_program_ID);
};

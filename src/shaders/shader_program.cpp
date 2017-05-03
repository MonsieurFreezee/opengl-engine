#include "shader_program.h"
#include <iostream>
#include <cstdlib>

void ShaderProgram::compile_shaders(const Shader &vertex_shader, const Shader &fragment_shader) const
{
    glAttachShader(m_shader_program_ID, vertex_shader.get_shader_ID());
    glAttachShader(m_shader_program_ID, fragment_shader.get_shader_ID());
    glLinkProgram(m_shader_program_ID);

    // Checks for error
    GLint success;
    glGetProgramiv(m_shader_program_ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        // Fancy way to optimize memory: query the length with GL_INFO_LOG_LENGTH
        GLint length;
        glGetProgramiv(m_shader_program_ID, GL_INFO_LOG_LENGTH, &length);
        GLchar log[length];
        glGetProgramInfoLog(m_shader_program_ID, length, nullptr, log);
        std::cerr << "Error while linking shaders: " << log << '\n';
        exit(-1);
    }

    glUseProgram(m_shader_program_ID);
}

ShaderProgram::ShaderProgram(Shader &vertex_shader, Shader &fragment_shader):
    m_shader_program_ID {glCreateProgram()}
{
    compile_shaders(vertex_shader, fragment_shader);
}

ShaderProgram::ShaderProgram(const std::string &vertex_shader_location, const std::string &fragment_shader_location):
    m_shader_program_ID {glCreateProgram()}
{
    Shader vertex_shader {vertex_shader_location, GL_VERTEX_SHADER};
    Shader fragment_shader {fragment_shader_location, GL_FRAGMENT_SHADER};
    compile_shaders(vertex_shader, fragment_shader);
}

GLuint ShaderProgram::get_ID() const
{
    return {m_shader_program_ID};
}

void ShaderProgram::use() const
{
    use(m_shader_program_ID);
}

void ShaderProgram::use(GLuint shader_program_ID)
{
    glUseProgram(shader_program_ID);
}

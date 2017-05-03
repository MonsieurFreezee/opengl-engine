#pragma once
#include <GL/glew.h>
#include <string>

class Shader
{
private:
    const GLuint m_shader_ID;
    const GLenum m_shader_type;

public:
    Shader(const std::string &location, GLenum shader_type);
    ~Shader();

    GLenum get_shader_type() const;
    GLuint get_shader_ID() const;
};

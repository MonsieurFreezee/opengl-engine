#pragma once
#include <GL/glew.h>
#include <string>

class Texture
{
private:
    const GLuint m_texture_ID;

    GLuint create_texture_ID() const;
public:
    Texture(const std::string &location);

    GLuint get_texture_ID() const;
    static void bind(const Texture &texture);
    static void bind(GLuint texture_id);
    void bind() const;
};

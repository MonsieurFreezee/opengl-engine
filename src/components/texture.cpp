#include "texture.h"
#include <SOIL/SOIL.h>
#include <sys/stat.h>
#include <stdexcept>
#include <iostream>

GLuint Texture::create_texture_ID() const
{
    GLuint texture_ID;
    glGenTextures(1, &texture_ID);
    return {texture_ID};
}

Texture::Texture(const std::string &location):
    m_texture_ID {create_texture_ID()}
{
    struct stat buffer;
    if (stat(location.c_str(), &buffer) != 0)
    {
        throw std::invalid_argument("Could not read file " + location + ". File does not exist.\n");
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height;
    unsigned char* image {SOIL_load_image(location.c_str(), &width, &height, 0, SOIL_LOAD_RGB)};

    glBindTexture(GL_TEXTURE_2D, m_texture_ID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint Texture::get_texture_ID() const
{
    return {m_texture_ID};
}

void Texture::bind(const Texture &texture)
{
    glBindTexture(GL_TEXTURE_2D, texture.get_texture_ID());
}

void Texture::bind(GLuint texture_id)
{
    glBindTexture(GL_TEXTURE_2D, texture_id);
}

void Texture::bind() const
{
    bind(*this);
}

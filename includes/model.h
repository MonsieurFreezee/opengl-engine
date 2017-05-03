#pragma once
#include "renderable.h"
#include "mesh.h"
#include "texture.h"
#include "shader_program.h"

class Model: public Renderable
{
private:
    const Mesh m_mesh;
    const Texture m_texture;

// protected:

public:
    void render(const ShaderProgram &shader_program) const;
    Model(const Mesh &mesh, const Texture &texture);
};

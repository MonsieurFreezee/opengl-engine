#pragma once
#include "shader_program.h"

class Renderable
{
public:
    virtual void render(const ShaderProgram &shader_program) const = 0;
};

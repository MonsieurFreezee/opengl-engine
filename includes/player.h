#pragma once
#include "entity.h"
#include "model.h"
#include "renderable.h"
#include "updateable.h"

class Player: public Entity, public Renderable, public Updateable
{
private:
    const Model m_model;

public:
    Player(const Entity &entity, const Model &model);
    Player(const Model &model);

    void render(const ShaderProgram &shader_program) const;
    void update();
};

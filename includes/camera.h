#pragma once
#include "entity.h"
#include "updateable.h"

class Camera: public Entity, public Updateable
{
public:
    Camera(const Position &position);

    void update();
};

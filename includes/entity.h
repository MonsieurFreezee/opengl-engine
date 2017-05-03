#pragma once
#include "position.h"
#include "rotation.h"

class Position;
class Rotation;

class Entity
{
private:
    Position m_position;
    Rotation m_rotation;

protected:
    Entity(const Position &position, const Rotation &rotation);
    Entity();

public:
    position_t get_position_X() const;
    position_t get_position_Y() const;
    position_t get_position_Z() const;

    rotation_t get_rotation_X() const;
    rotation_t get_rotation_Y() const;
    rotation_t get_rotation_Z() const;

    void set_position_X(position_t value);
    void set_position_Y(position_t value);
    void set_position_Z(position_t value);

    void set_rotation_X(position_t value);
    void set_rotation_Y(position_t value);
    void set_rotation_Z(position_t value);
};

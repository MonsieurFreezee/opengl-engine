#include "entity.h"

Entity::Entity(const Position &position, const Rotation &rotation):
    m_position {position},
    m_rotation {rotation}
{

}

Entity::Entity():
    m_position {0.0f, 0.0f, 0.0f},
    m_rotation {0.0f, 0.0f, 0.0f}
{

}

position_t Entity::get_position_X() const
{
    return {m_position.get_X()};
}

position_t Entity::get_position_Y() const
{
    return {m_position.get_Y()};
}

position_t Entity::get_position_Z() const
{
    return {m_position.get_Z()};
}

rotation_t Entity::get_rotation_X() const
{
    return {m_rotation.get_X()};
}

rotation_t Entity::get_rotation_Y() const
{
    return {m_rotation.get_Y()};
}

rotation_t Entity::get_rotation_Z() const
{
    return {m_rotation.get_Z()};
}

void Entity::set_position_X(position_t value)
{
    m_position.set_X(value);
}

void Entity::set_position_Y(position_t value)
{
    m_position.set_Y(value);
}

void Entity::set_position_Z(position_t value)
{
    m_position.set_Z(value);
}

void Entity::set_rotation_X(position_t value)
{
    m_rotation.set_X(value);
}

void Entity::set_rotation_Y(position_t value)
{
    m_rotation.set_Y(value);
}

void Entity::set_rotation_Z(position_t value)
{
    m_rotation.set_Z(value);
}

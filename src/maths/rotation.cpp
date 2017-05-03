#include "rotation.h"

Rotation::Rotation(rotation_t x, rotation_t y, rotation_t z):
    m_x {x},
    m_y {y},
    m_z {z}
{

}

Rotation::Rotation():
    m_x {0.0f},
    m_y {0.0f},
    m_z {0.0f}
{

}

void Rotation::set_X(rotation_t x)
{
    m_x = x;
}

void Rotation::set_Y(rotation_t y)
{
    m_y = y;
}

void Rotation::set_Z(rotation_t z)
{
    m_z = z;
}

rotation_t Rotation::get_X() const
{
    return {m_x};
}

rotation_t Rotation::get_Y() const
{
    return {m_y};
}

rotation_t Rotation::get_Z() const
{
    return {m_z};
}

#include "position.h"

Position::Position(position_t x, position_t y, position_t z):
    m_x {x},
    m_y {y},
    m_z {z}
{

}

Position::Position():
    m_x {0.0f},
    m_y {0.0f},
    m_z {0.0f}
{

}

void Position::set_X(position_t x)
{
    m_x = x;
}

void Position::set_Y(position_t y)
{
    m_y = y;
}

void Position::set_Z(position_t z)
{
    m_z = z;
}

position_t Position::get_X() const
{
    return {m_x};
}

position_t Position::get_Y() const
{
    return {m_y};
}

position_t Position::get_Z() const
{
    return {m_z};
}

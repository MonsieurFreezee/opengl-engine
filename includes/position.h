#pragma once

typedef float position_t;

class Position
{
private:
    position_t m_x;
    position_t m_y;
    position_t m_z;

public:
    Position(position_t x, position_t y, position_t z);
    Position();

    void set_X(position_t x);
    void set_Y(position_t y);
    void set_Z(position_t z);

    position_t get_X() const;
    position_t get_Y() const;
    position_t get_Z() const;
};

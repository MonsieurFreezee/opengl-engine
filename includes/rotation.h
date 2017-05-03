#pragma once

typedef float rotation_t;

class Rotation
{
private:
    rotation_t m_x;
    rotation_t m_y;
    rotation_t m_z;

public:
    Rotation(rotation_t x, rotation_t y, rotation_t z);
    Rotation();

    void set_X(rotation_t x);
    void set_Y(rotation_t y);
    void set_Z(rotation_t z);

    rotation_t get_X() const;
    rotation_t get_Y() const;
    rotation_t get_Z() const;
};

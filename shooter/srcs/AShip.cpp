#include "../includes/AShip.hpp"

AShip::AShip(void)
{
    return;
}

AShip::~AShip(void)
{
    return;
}

AShip::AShip(const AShip & toCopy)
{
    *this = toCopy;
    return;
}

AShip & AShip::operator= (const AShip & rhs)
{
    _height = rhs._height;
    _width = rhs._width;
    _x = rhs._x;
    _y = rhs._y;
    _speed = rhs._speed;
    _direction = rhs._direction;
    _active = rhs._active;
    return *this;
}

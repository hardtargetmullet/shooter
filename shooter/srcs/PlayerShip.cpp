#include "../includes/PlayerShip.hpp"
#include "../includes/AShip.hpp"
#include <iostream>

PlayerShip::PlayerShip(int x, int y)
{
	this->_x = x;
	this->_y = y;
    this->_height = 1;
    this->_width = 1;
    this->_speed = 0;
    this->_direction = 1;
	this->_design = "}=(0)={";
	this->_active = true;
    return;
}

PlayerShip::~PlayerShip(void)
{

    return;
}

PlayerShip::PlayerShip(const PlayerShip & toCopy)
{
    *this = toCopy;
    return;
}

PlayerShip& PlayerShip::operator=(const PlayerShip & rhs)
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

void    PlayerShip::update(void)
{
}

void    PlayerShip::draw(void)
{
    for (size_t i = 0; i < _design.length(); i++)
        mvprintw(_x, _y + i, "%c", _design[i]);
}

bool     PlayerShip::collide(int x, int y, int len) {

    for (int i = 0; i < len; i++)
        for (int j = 0; j < (int)_design.length(); j++)
            if(this->getX() + j == x + i && this->getY() == y)
                return true;
    return false;
}

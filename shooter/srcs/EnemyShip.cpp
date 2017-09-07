#include "../includes/EnemyShip.hpp"
#include "../includes/AShip.hpp"

EnemyShip::EnemyShip(void) : AShip::AShip() 
{
    _height = 1;
    _width = 1;
    _x = 0;
    _y = 0;
    _speed = 1;
    _direction = 0;
    _active = false;
    _design = "<vv>";
    return;
}

EnemyShip::~EnemyShip(void)
{

    return;
}

EnemyShip::EnemyShip(const EnemyShip & toCopy)
{
    *this = toCopy;
    return;
}

EnemyShip & EnemyShip::operator= (const EnemyShip & rhs)
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

void    EnemyShip::draw(void)
{
    for (size_t i = 0; i < _design.length(); i++)
        mvprintw(_x, _y + i, "%c", _design[i]);
}

void    EnemyShip::update(void)
{
	if (_direction == 0)
    	this->_x += _speed;
}

bool     EnemyShip::collide(int x, int y, int len) {

    for (int i = 0; i < len; i++)
        for (int j = 0; j < (int)_design.length(); j++)
            if(this->getX() + j == x + i && this->getY() == y)
                return true;
    return false;
}

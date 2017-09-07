#include "../includes/Missle.hpp"

Missle::Missle(int damage, std::string design)
{
    this->_damage = damage;
    this->_design = design;
    this->_direction = 0;
	this->_speed = 1;
}

Missle::~Missle(void)
{
    return ;
}

Missle::Missle(const Missle& toCopy)
{
    *this = toCopy;
}

Missle& Missle::operator=(const Missle& rhs)
{
    this->_height = rhs._height;
    this->_width = rhs._width;
    this->_x = rhs._x;
    this->_y = rhs._y;
    this->_speed = rhs._speed;
    this->_direction = rhs._direction;
    this->_active = rhs._active;
    return *this;
}

int Missle::getDamage(void)
{
    return this->_damage;
}

void Missle::setDamage(int damage)
{
    this->_damage = damage;
}

void Missle::draw(void)
{
    mvprintw(_x, _y, "%c", _design[0]);
}

void Missle::update(void)
{
	if (_direction == 1)
    	this->_x -= _speed;
	if (_direction == 0)
    	this->_x += _speed;
}

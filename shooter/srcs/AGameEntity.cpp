#include "../includes/AGameEntity.hpp"

AGameEntity::AGameEntity(void)
{
    return ;
}

AGameEntity::~AGameEntity(void)
{
    return ;
}

AGameEntity& AGameEntity::operator=(const AGameEntity& rhs)
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

AGameEntity::AGameEntity(const AGameEntity& toCopy)
{
    *this = toCopy;
}

int AGameEntity::getHeight(void)
{
    return this->_height;
}

int AGameEntity::getWidth(void)
{
    return this->_width;
}

int AGameEntity::getX(void)
{
    return this->_y;
}

int AGameEntity::getY(void)
{
    return this->_x;
}

int AGameEntity::getSpeed(void)
{
    return this->_speed;
}

int AGameEntity::getDirection(void)
{
    return this->_direction;
}

bool AGameEntity::getStatus(void)
{
    return this->_active;
}

std::string AGameEntity::getDesign(void)
{
    return this->_design;
}

void AGameEntity::setHeight(int h)
{
    this->_height = h;
}

void AGameEntity::setWidth(int w)
{
    this->_width = w;
}

void AGameEntity::setX(int x)
{
    this->_y = x;
}

void AGameEntity::setY(int y)
{
    this->_x = y;
}

void AGameEntity::setSpeed(int speed)
{
    this->_speed = speed;
}

void AGameEntity::setDirection(int direction)
{
    this->_direction = direction;
}

void AGameEntity::setStatus(bool status)
{
    this->_active = status;
}

void AGameEntity::setDesign(std::string bullet)
{
    this->_design = bullet;
}

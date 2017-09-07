#ifndef AGAMEENTITY_H
# define AGAMEENTITY_H

#include <string>
#include <iostream>
#include <ncurses.h>

class AGameEntity {
    public:
        AGameEntity();
        virtual ~AGameEntity() = 0;
        AGameEntity(const AGameEntity& toCopy);
        AGameEntity& operator=(const AGameEntity& rhs);

//      Getters
        int             getHeight(void);
        int             getWidth(void);
        int             getX(void);
        int             getY(void);
        int             getSpeed(void);
        int             getDirection(void);
        bool            getStatus(void);
        std::string     getDesign(void);
//      Setters
        void            setHeight(int h);
        void            setWidth(int w);
        void            setX(int x);
        void            setY(int y);
        void            setSpeed(int s);
        void            setDirection(int d);
        void            setStatus(bool status);
        void            setDesign(std::string bullet);
        virtual void    draw() = 0;
        virtual void    update() = 0;

    protected:
        //Location*   _point;
        int         _height;
        int         _width;
        int         _x;
        int         _y;
        int         _speed;
        int         _direction;
        bool        _active;
        std::string _design;

};
#endif

/*
	if (_direction == 1)//UP)
    	this->_y += _speed; // % fps
	if (_direction == 0)
		this->_y -= _speed; // % fps
	this->_y += 1;
    */

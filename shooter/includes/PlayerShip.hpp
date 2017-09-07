#ifndef PLAYERSHIP_H
# define PLAYERSHIP_H

#include "AShip.hpp"

class PlayerShip : public AShip {
    public:
        PlayerShip(int x=50, int y=50);
        ~PlayerShip(void);
        PlayerShip(const PlayerShip& toCopy);
        PlayerShip& operator=(const PlayerShip& rhs);
        void update(void);
        void draw(void);
        bool collide(int x, int y, int len);
    protected:

};

#endif

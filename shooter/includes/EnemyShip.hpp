#ifndef ENEMYSHIP_H
# define ENEMYSHIP_H

#include "../includes/AShip.hpp"

class EnemyShip : public AShip {
    public:
        EnemyShip(void);
        ~EnemyShip(void);
        EnemyShip(const EnemyShip& toCopy);
        EnemyShip& operator=(const EnemyShip& rhs);
        void update(void);
        void draw(void);
        bool collide(int x, int y, int len);
    protected:

};

#endif

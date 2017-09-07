#ifndef MISSLE_H
# define MISSLE_H

#include "AGameEntity.hpp"

class Missle : public AGameEntity {
    public:
        Missle(int damage=1, std::string design="|"); // Player missles
        ~Missle();
        Missle(const Missle& toCopy);
        Missle& operator=(const Missle& rhs);

        int     getDamage(void);
        void    setDamage(int);
        void    draw(void);
        void    update(void);

    protected:
        int     _damage;
};

#endif

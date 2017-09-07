#ifndef ASHIP_H
# define ASHIP_H

#include "AGameEntity.hpp"

class AShip : public AGameEntity {
    public:
        AShip(void);
        virtual ~AShip(void) = 0;
        AShip(const AShip& toCopy);
        AShip& operator=(const AShip& rhs);

    protected:
};

#endif

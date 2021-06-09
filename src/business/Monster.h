#ifndef MONSTER_H
#define MONSTER_H

#include "AbstractPerso.h"

class Monster : public AbstractPerso
{
public :
    Monster(int id, int idLocation, sf::String level);
};

#endif //MONSTER_H
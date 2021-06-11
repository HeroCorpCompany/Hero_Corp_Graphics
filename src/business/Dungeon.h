#ifndef DUNGEON_H
#define DUNGEON_H

#include "AbstractLocation.h"

class Dungeon : public AbstractLocation
{
public :
    Dungeon(int id, std::size_t x, std::size_t y);
};

#endif //DUNGEON_H
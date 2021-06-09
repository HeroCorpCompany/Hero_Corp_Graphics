#ifndef DUNGEON_H
#define DUNGEON_H

#include "AbstractLocation.h"
#include "../tools/json.hpp"

using json = nlohmann::json;

class Dungeon : public AbstractLocation
{
public :
    Dungeon(int id, std::size_t x, std::size_t y);

private :
    json m_monsters;
    json m_hunters;
    int pop;
};

#endif //DUNGEON_H
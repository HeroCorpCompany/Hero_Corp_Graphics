#ifndef DUNGEON_H
#define DUNGEON_H

#include "AbstractLocation.h"

class Dungeon : public AbstractLocation
{
public :
    Dungeon(int id, std::size_t x, std::size_t y);

    virtual std::vector<Hunter*> getHunters() const;
    virtual std::vector<Monster*> getMonsters() const;
    virtual void setHunters(std::vector<Hunter*>);
    virtual void setMonsters(std::vector<Monster*>);
    virtual void setGolds(int);

private :
    std::vector<Monster*> m_monsters;
    std::vector<Hunter*> m_hunters;
    std::size_t m_pop;
};

#endif //DUNGEON_H
#ifndef GUILD_H
#define GUILD_H

#include "AbstractLocation.h"

class Guild : public AbstractLocation
{
public :
    Guild(int id, std::size_t x, std::size_t y);

    virtual std::vector<Hunter*> getHunters() const;
    virtual std::vector<Monster*> getMonsters() const;
    virtual void setHunters(std::vector<Hunter*>);
    virtual void setMonsters(std::vector<Monster*>);
    virtual void setGolds(int);

private :
    std::vector<Hunter*> m_hunters;
    int m_golds;
    std::size_t m_pop;
};

#endif //GUILD_H
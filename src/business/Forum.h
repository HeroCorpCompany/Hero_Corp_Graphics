#ifndef FORUM_H
#define FORUM_H

#include <vector>

#include "AbstractLocation.h"

class Forum : public AbstractLocation
{
public :
    Forum(int id, std::size_t x, std::size_t y);

    int getPop() const;

    virtual std::vector<Hunter*> getHunters() const;
    virtual std::vector<Monster*> getMonsters() const;
    virtual void setHunters(std::vector<Hunter*>);
    virtual void setMonsters(std::vector<Monster*>);
    virtual void setGolds(int);

private :
    std::vector<Hunter*> m_hunters;
    std::size_t m_pop;
};

#endif //FORUM_H
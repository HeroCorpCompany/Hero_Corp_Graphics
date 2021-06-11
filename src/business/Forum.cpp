#include "Forum.h"

Forum::Forum(int id, std::size_t x, std::size_t y)
: AbstractLocation(id, x, y)
{
    setBodyColor(sf::Color(0, 0, 255));
    setText("Ceci est le forum");
}

int Forum::getPop() const
{
    return m_pop;
}

std::vector<Hunter*> Forum::getHunters() const
{
    return m_hunters;
}

void Forum::setHunters(std::vector<Hunter*> hunters)
{
    m_hunters = hunters;
    m_pop = m_hunters.size();
}

std::vector<Monster*> Forum::getMonsters() const
{
    std::vector<Monster*> monsters;
    return monsters;
}
void Forum::setMonsters(std::vector<Monster*> monsters){}
void Forum::setGolds(int){}

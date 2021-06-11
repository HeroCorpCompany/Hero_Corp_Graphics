#include "Guild.h"

Guild::Guild(int id, std::size_t x, std::size_t y)
: AbstractLocation(id, x, y)
{
    setBodyColor(sf::Color(255, 255, 0));
    setText("Ceci est une guilde");
}

std::vector<Hunter*> Guild::getHunters() const
{
    return m_hunters;
}

std::vector<Monster*> Guild::getMonsters() const
{
    std::vector<Monster*> monstres;
    return monstres;
}

void Guild::setHunters(std::vector<Hunter*> hunters)
{
    m_hunters = hunters;
    m_pop = m_hunters.size();
}

void Guild::setMonsters(std::vector<Monster*> monsters){}

void Guild::setGolds(int golds)
{
    m_golds = golds;
}
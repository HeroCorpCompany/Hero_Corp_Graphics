#include "Dungeon.h"

Dungeon::Dungeon(int id, std::size_t x, std::size_t y)
: AbstractLocation(id, x, y)
{
    setBodyColor(sf::Color(255, 0, 0));
    setText("Ceci est un donjon");
}

std::vector<Hunter*> Dungeon::getHunters() const
{
    return m_hunters;
}

std::vector<Monster*> Dungeon::getMonsters() const
{
    return m_monsters;
}

void Dungeon::setHunters(std::vector<Hunter*> hunters)
{
    m_hunters = hunters;
    m_pop = m_hunters.size() + m_monsters.size();
}

void Dungeon::setMonsters(std::vector<Monster*> monsters)
{
    m_monsters = monsters;
    m_pop = m_hunters.size() + m_monsters.size();
}

void Dungeon::setGolds(int){}

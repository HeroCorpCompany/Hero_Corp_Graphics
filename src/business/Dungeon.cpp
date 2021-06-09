#include "Dungeon.h"

Dungeon::Dungeon(std::size_t x, std::size_t y)
: AbstractLocation(x, y)
{
    m_body.setFillColor(sf::Color(255, 0, 0));
}
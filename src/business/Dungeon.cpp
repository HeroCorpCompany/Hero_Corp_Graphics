#include "Dungeon.h"

Dungeon::Dungeon(std::size_t x, std::size_t y)
: AbstractLocation(x, y)
{
    setBodyColor(sf::Color(255, 0, 0));
}
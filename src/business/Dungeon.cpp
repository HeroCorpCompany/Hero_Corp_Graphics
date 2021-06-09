#include "Dungeon.h"

Dungeon::Dungeon(int id, std::size_t x, std::size_t y)
: AbstractLocation(id, x, y)
{
    setBodyColor(sf::Color(255, 0, 0));
    setText("Ceci est un donjon");
}
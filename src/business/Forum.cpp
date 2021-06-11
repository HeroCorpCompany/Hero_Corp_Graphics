#include "Forum.h"

Forum::Forum(int id, std::size_t x, std::size_t y)
: AbstractLocation(id, x, y, 0)
{
    setBodyColor(sf::Color(0, 0, 255));
    setText("Ceci est le forum");
}
#include "Forum.h"

Forum::Forum(std::size_t x, std::size_t y)
: AbstractLocation(x, y)
{
    setBodyColor(sf::Color(0, 0, 255));
}
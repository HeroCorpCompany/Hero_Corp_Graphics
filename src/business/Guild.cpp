#include "Guild.h"

Guild::Guild(std::size_t x, std::size_t y)
: AbstractLocation(x, y)
{
    m_body.setFillColor(sf::Color(255, 255, 0));
}
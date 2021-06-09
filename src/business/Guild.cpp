#include "Guild.h"

Guild::Guild(std::size_t x, std::size_t y)
: AbstractLocation(x, y)
{
    setBodyColor(sf::Color(255, 255, 0));
    setText("Ceci est une guilde");
}
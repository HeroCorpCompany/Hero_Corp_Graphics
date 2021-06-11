#include "Guild.h"

Guild::Guild(int id, std::size_t x, std::size_t y, int golds)
: AbstractLocation(id, x, y, golds)
{
    setBodyColor(sf::Color(255, 255, 0));
    setText("Ceci est une guilde avec $" + std::to_string(golds));
}
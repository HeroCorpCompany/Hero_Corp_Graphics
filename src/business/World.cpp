#include "World.h"

World::World()
{
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.clear(sf::Color(30, 140, 30));
}
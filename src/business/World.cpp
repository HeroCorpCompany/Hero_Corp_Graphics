#include "World.h"

World::World()
: m_sizex(SIZE_TABLE_X)
, m_sizey(SIZE_TABLE_Y)
, m_table(m_sizex, std::vector<Type>(m_sizey, Type::None))
{
    m_locations.push_back(new class Forum(20, 13));
    m_locations.push_back(new class Guild(12, 20));
    m_locations.push_back(new class Guild(31, 14));
    m_locations.push_back(new class Guild(12, 12));
    m_locations.push_back(new class Dungeon(12, 15));
    m_locations.push_back(new class Dungeon(26, 19));
    m_locations.push_back(new class Dungeon(7, 17));
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.clear(sf::Color(30, 140, 30));
    sf::RectangleShape rectangle;
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setSize({float(SIZE_SCREEN_X - SIZE_MENU)/m_sizex, float(SIZE_SCREEN_Y)/m_sizey});
    
    for (std::size_t i = 0; i < m_locations.size(); ++i)
    {
        target.draw(*m_locations[i]);
    }

    rectangle.setSize({SIZE_MENU, float(SIZE_SCREEN_Y)});
    rectangle.setPosition(m_sizex*float(SIZE_SCREEN_X - SIZE_MENU)/m_sizex, 0.f);
    rectangle.setFillColor(sf::Color(200, 173, 127));
    rectangle.setOutlineThickness(-5.f);
    target.draw(rectangle, states);
}
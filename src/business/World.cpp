#include "World.h"

World::World()
: m_idOfSelectedLocation(0)
, m_sizex(SIZE_TABLE_X)
, m_sizey(SIZE_TABLE_Y)
, m_table(m_sizex, std::vector<Type>(m_sizey, Type::None))
, m_updateTime(10.f)
, m_timeSinceLastUpdate(m_updateTime)
{
}

void World::update(sf::Vector2i mousePosition)
{
    for (std::size_t i = 0; i < m_locations.size(); ++i)
    {
        m_locations[i]->update(mousePosition);
    }

    if (m_timeSinceLastUpdate >= m_updateTime)
    {
        m_timeSinceLastUpdate = 0.f;
        m_api.updateWorld(this);
        //m_locations = m_api.getLocations();
        //m_hunters = m_api.getHunters();
    }

    m_timeSinceLastUpdate += 1/FPS;
}

void World::setLocations(std::vector<AbstractLocation*>& locations)
{
    m_locations = locations;
}

void World::setHunters(std::vector<Hunter*>& hunters)
{
    m_hunters = hunters;
}

void World::setMonsters(std::vector<Monster*>& monsters)
{
    m_monsters = monsters;
}

void World::setStatistics(int time, int nbHunt, int nbDonj, int nbGui)
{
    m_timeIteration = time;
    m_nbHunters = nbHunt;
    m_nbDungeons = nbDonj;
    m_nbGuilds = nbGui;
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.clear(sf::Color(30, 140, 30));

    sf::RectangleShape rectangle;
    rectangle.setSize({SIZE_MENU, float(SIZE_SCREEN_Y)});
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setPosition(m_sizex*float(SIZE_SCREEN_X - SIZE_MENU)/m_sizex, 0.f);
    rectangle.setFillColor(sf::Color(200, 173, 127));
    rectangle.setOutlineThickness(-5.f);
    target.draw(rectangle, states);

    rectangle.setSize({float(SIZE_SCREEN_X - SIZE_MENU)/m_sizex, float(SIZE_SCREEN_Y)/m_sizey});
    
    for (std::size_t i = 0; i < m_locations.size(); ++i)
    {
        if (!m_locations[i]->isSelected())
        {
            target.draw(*m_locations[i]);
        }
    }
    for (std::size_t i = 0; i < m_locations.size(); ++i)
    {
        if (m_locations[i]->isSelected())
        {
            target.draw(*m_locations[i]);
        }
    }
}
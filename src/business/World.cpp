#include "World.h"

World::World()
: m_idOfSelectedLocation(0)
, m_sizex(SIZE_TABLE_X)
, m_sizey(SIZE_TABLE_Y)
, m_table(m_sizex, std::vector<Type>(m_sizey, Type::None))
, m_updateTime(30.f)
, m_timeSinceLastUpdate(m_updateTime)
{
    if (!m_font.loadFromFile("assets/fonts/arial.ttf"))
    {
        throw std::runtime_error ("Failed to load 'assets/fonts/arial.ttf'");
    }
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

void World::setIdSelected(int id)
{
    m_idOfSelectedLocation = id;
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

std::vector<AbstractLocation*> World::getLocations() const
{
    return m_locations;
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

    sf::Text text;
    text.setPosition(SIZE_SCREEN_X - SIZE_MENU + 20, 20);
    text.setFont(m_font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(18u);
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(1.f);
    text.setString( "Temps : " + std::to_string(m_timeIteration) + "\n"
                    "Nombre de chasseurs : " + std::to_string(m_nbHunters) + "\n"
                    "Nombre de donjons : " + std::to_string(m_nbDungeons) + "\n"
                    "Nombre de guildes : " + std::to_string(m_nbGuilds) + "\n");
    target.draw(text);
    text.move({0, 20});
    if (m_idOfSelectedLocation)
    {
        for (std::size_t i = 0; i < m_hunters.size(); ++i)
        {
            if (m_hunters[i]->getIdLocation() == m_idOfSelectedLocation)
            {
                text.move({0, text.getLocalBounds().height});
                text.setString("Chassseur de classe " + m_hunters[i]->getLevel());
                target.draw(text);
            }
        }
        for (std::size_t i = 0; i < m_monsters.size(); ++i)
        {
            if (m_monsters[i]->getIdLocation() == m_idOfSelectedLocation)
            {
                text.move({0, text.getLocalBounds().height});
                text.setString("Monstre de classe " + m_monsters[i]->getLevel());
                target.draw(text);
            }
        }
    }
    
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
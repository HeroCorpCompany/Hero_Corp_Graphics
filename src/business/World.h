#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "../api/ApiManager.h"

enum Type 
{
    None = 0,
    Forum = 1,
    Guild = 2,
    Dungeon = 3,
};

using table = std::vector<std::vector<Type>>;

class World : public sf::Drawable
{
public :
    World();
    void update(sf::Vector2i mousePosition);

    void setIdSelected(int);
    void setLocations(std::vector<AbstractLocation*>&);
    void setHunters(std::vector<Hunter*>&);
    void setMonsters(std::vector<Monster*>&);
    void setStatistics(int time, int nbHunt, int nbDonj, int nbGui);

    std::vector<AbstractLocation*> getLocations() const;

private :
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

private :
    std::vector<AbstractLocation*> m_locations;
    std::vector<Hunter*> m_hunters;
    std::vector<Monster*> m_monsters;
    int m_timeIteration;
    int m_nbHunters;
    int m_nbDungeons;
    int m_nbGuilds;
    
    int m_idOfSelectedLocation;

    std::size_t m_sizex;
    std::size_t m_sizey;
    table m_table;

    float m_updateTime;
    float m_timeSinceLastUpdate;
    ApiManager m_api;
};

#endif //WORLD_H
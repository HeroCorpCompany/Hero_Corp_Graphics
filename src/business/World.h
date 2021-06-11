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

private :
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

private :
    std::vector<AbstractLocation*> m_locations;
    std::size_t m_sizex;
    std::size_t m_sizey;
    table m_table;

    float m_updateTime;
    float m_timeSinceLastUpdate;
};

#endif //WORLD_H
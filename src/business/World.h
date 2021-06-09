#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Forum.h"
#include "Dungeon.h"
#include "Guild.h"

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
};

#endif //WORLD_H
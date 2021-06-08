#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include "Forum.h"

class World : public sf::Drawable
{
public :
    World();
    void update();

private :
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

private :
    json m_locations;
};

#endif //WORLD_H
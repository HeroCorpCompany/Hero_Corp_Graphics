#ifndef ABSTRACT_LOCATION_H
#define ABSTRACT_LOCATION_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "../engine/CONSTANTS.hpp"

class AbstractLocation : public sf::Drawable
{
public :
    AbstractLocation();
    AbstractLocation(std::size_t x, std::size_t y);

private :
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

protected :
    std::size_t x;
    std::size_t y;

    sf::RectangleShape m_body;
};

#endif
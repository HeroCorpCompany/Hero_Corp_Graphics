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

    void setBodyColor(sf::Color);

    void update(sf::Vector2i mousePosition);

private :
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

protected :
    std::size_t x;
    std::size_t y;
    bool m_isSelected;

    sf::RectangleShape m_body;
    sf::RectangleShape m_bodySelected;
};

#endif
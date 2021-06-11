#ifndef ABSTRACT_LOCATION_H
#define ABSTRACT_LOCATION_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Hunter.h"
#include "Monster.h"
#include "../engine/CONSTANTS.hpp"

class AbstractLocation : public sf::Drawable
{
public :
    AbstractLocation();
    AbstractLocation(int id, std::size_t x, std::size_t y, int golds);

    int getID() const;
    int getGolds() const;
    bool isSelected() const;

    void setBodyColor(sf::Color);
    void setText(sf::String);

    void update(sf::Vector2i mousePosition);

private :
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

protected :
    int id;
    std::size_t x;
    std::size_t y;
    int m_golds;
    bool m_isSelected;

    sf::Font m_font;
    sf::Text m_text;

    sf::RectangleShape m_body;
    sf::RectangleShape m_bodySelected;
};

#endif
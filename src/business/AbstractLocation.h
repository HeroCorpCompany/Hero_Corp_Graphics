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
    AbstractLocation(int id, std::size_t x, std::size_t y);

    int getID() const;
    bool isSelected() const;

    virtual std::vector<Hunter*> getHunters() const = 0;
    virtual std::vector<Monster*> getMonsters() const = 0;
    virtual void setHunters(std::vector<Hunter*>) = 0;
    virtual void setMonsters(std::vector<Monster*>) = 0;
    virtual void setGolds(int) = 0;

    void setBodyColor(sf::Color);
    void setText(sf::String);

    void update(sf::Vector2i mousePosition);

private :
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

protected :
    int id;
    std::size_t x;
    std::size_t y;
    bool m_isSelected;

    sf::Font m_font;
    sf::Text m_text;

    sf::RectangleShape m_body;
    sf::RectangleShape m_bodySelected;
};

#endif
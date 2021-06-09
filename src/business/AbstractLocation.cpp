#include "AbstractLocation.h"

AbstractLocation::AbstractLocation(std::size_t x, std::size_t y)
: x(x)
, y(y)
{
    m_body.setSize({float(SIZE_SCREEN_X - SIZE_MENU)/SIZE_TABLE_X, float(SIZE_SCREEN_Y)/SIZE_TABLE_Y});
    m_body.setPosition(x*float(SIZE_SCREEN_X - SIZE_MENU)/SIZE_TABLE_X, y*float(SIZE_SCREEN_Y)/SIZE_TABLE_Y);

    m_bodySelected = m_body;
    sf::FloatRect rect = m_bodySelected.getLocalBounds();
    m_bodySelected.setOrigin({rect.height/2, rect.width/2});
    m_bodySelected.move(rect.height/2, rect.width/2);
    m_bodySelected.scale(1.3, 1.3);
}

void AbstractLocation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (m_isSelected)
    {
        target.draw(m_bodySelected);
    }
    else
    {
        target.draw(m_body);
    }
}

void AbstractLocation::setBodyColor(sf::Color color)
{
    m_body.setFillColor(color);
    m_bodySelected.setFillColor(color);
}

void AbstractLocation::update(sf::Vector2i mousePosition)
{
    if (mousePosition.x > x*float(SIZE_SCREEN_X - SIZE_MENU)/SIZE_TABLE_X &&
        mousePosition.x < (x+1)*float(SIZE_SCREEN_X - SIZE_MENU)/SIZE_TABLE_X &&
        mousePosition.y > y*float(SIZE_SCREEN_Y)/SIZE_TABLE_Y &&
        mousePosition.y < (y+1)*float(SIZE_SCREEN_Y)/SIZE_TABLE_Y)
    {
        m_isSelected = true;
    }
    else
    {
        m_isSelected = false;
    }
}
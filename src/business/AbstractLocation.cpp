#include "AbstractLocation.h"

AbstractLocation::AbstractLocation(std::size_t x, std::size_t y)
: x(x)
, y(y)
{
    m_body.setSize({float(SIZE_SCREEN_X - SIZE_MENU)/SIZE_TABLE_X, float(SIZE_SCREEN_Y)/SIZE_TABLE_Y});
    m_body.setPosition(x*float(SIZE_SCREEN_X - SIZE_MENU)/SIZE_TABLE_X, y*float(SIZE_SCREEN_Y)/SIZE_TABLE_Y);
}

void AbstractLocation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_body);
}
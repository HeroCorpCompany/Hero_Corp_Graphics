#include "AbstractLocation.h"

AbstractLocation::AbstractLocation(int id, std::size_t x, std::size_t y)
: id(id)
, x(x)
, y(y)
{
    m_body.setSize({float(SIZE_SCREEN_X - SIZE_MENU)/SIZE_TABLE_X, float(SIZE_SCREEN_Y)/SIZE_TABLE_Y});
    m_body.setPosition(x*float(SIZE_SCREEN_X - SIZE_MENU)/SIZE_TABLE_X, y*float(SIZE_SCREEN_Y)/SIZE_TABLE_Y);
    m_body.setOutlineThickness(1.f);
    m_body.setOutlineColor(sf::Color::Black);

    m_bodySelected = m_body;
    sf::FloatRect rect = m_bodySelected.getLocalBounds();
    m_bodySelected.setOrigin({rect.height/2, rect.width/2});
    m_bodySelected.move(rect.height/2, rect.width/2);
    m_bodySelected.scale(1.3, 1.3);

    if (!m_font.loadFromFile("assets/fonts/arial.ttf"))
    {
        throw std::runtime_error ("Textbox::build() - Failed to load 'assets/fonts/arial.ttf'");
    }
    m_text.setPosition((x+1)*float(SIZE_SCREEN_X - SIZE_MENU)/SIZE_TABLE_X + 10, y*float(SIZE_SCREEN_Y)/SIZE_TABLE_Y);
    m_text.setFont(m_font);
    m_text.setFillColor(sf::Color::White);
    m_text.setCharacterSize(20u);
    m_text.setStyle(sf::Text::Bold);
    m_text.setOutlineColor(sf::Color::Black);
    m_text.setOutlineThickness(1.f);
    m_text.setString("Hello World");
}

void AbstractLocation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (m_isSelected)
    {
        target.draw(m_bodySelected);
        target.draw(m_text);
    }
    else
    {
        target.draw(m_body);
    }
}

int AbstractLocation::getID() const
{
    return id;
}

bool AbstractLocation::isSelected() const
{
    return m_isSelected;
}

void AbstractLocation::setBodyColor(sf::Color color)
{
    m_body.setFillColor(color);
    m_bodySelected.setFillColor(color);
}

void AbstractLocation::setText(sf::String newText)
{
    m_text.setString(newText);
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
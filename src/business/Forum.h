#ifndef FORUM_H
#define FORUM_H

#include <SFML/Graphics.hpp>

#include "../tools/json.hpp"

using json = nlohmann::json;

class Forum
{
public :
    Forum();

private :
    sf::CircleShape m_cercle;
    int x;
    int y;
    json m_chasseurs;
};

#endif //FORUM_H
#ifndef ABSTRACT_PERSO_H
#define ABSTRACT_PERSO_H

#include <SFML/Graphics.hpp>

class AbstractPerso
{
public :
    AbstractPerso(int id, int idLocation, sf::String level);

public :
    int getId() const;
    int getIdLocation() const;
    sf::String getLevel() const;

private :
    int id;
    int idLocation;
    sf::String level;
};

#endif //ABSTRACT_PERSO_H
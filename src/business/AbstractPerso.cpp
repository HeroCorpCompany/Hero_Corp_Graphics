#include "AbstractPerso.h"

AbstractPerso::AbstractPerso(int id, int idLocation, sf::String level)
: id(id)
, idLocation(idLocation)
, level(level)
{
}

int AbstractPerso::getId() const
{
    return id;
}

int AbstractPerso::getIdLocation() const
{
    return idLocation;
}

sf::String AbstractPerso::getLevel() const
{
    return level;
}
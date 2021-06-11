#include "Hunter.h"

Hunter::Hunter(int id, int idLocation, sf::String level, int golds, int age)
: AbstractPerso(id, idLocation, level)
, golds(golds)
, age(age)
{
}

int Hunter::getGolds() const
{
    return golds;
}

int Hunter::getAge() const
{
    return age;
}
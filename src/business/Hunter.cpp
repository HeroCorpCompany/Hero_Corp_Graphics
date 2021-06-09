#include "Hunter.h"

Hunter::Hunter(int id, int idLocation, sf::String level, int golds)
: AbstractPerso(id, idLocation, level)
, golds(golds)
{
}
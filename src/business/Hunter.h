#ifndef HUNTER_H
#define HUNTER_H

#include "AbstractPerso.h"

class Hunter : public AbstractPerso
{
public :
    Hunter(int id, int idLocation, sf::String level, int golds);

    int getGolds() const;

private :
    int golds;
};

#endif //HUNTER_H
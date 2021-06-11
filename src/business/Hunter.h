#ifndef HUNTER_H
#define HUNTER_H

#include "AbstractPerso.h"

class Hunter : public AbstractPerso
{
public :
    Hunter(int id, int idLocation, sf::String level, int golds, int age);

    int getGolds() const;
    int getAge() const;

private :
    int golds;
    int age;
};

#endif //HUNTER_H
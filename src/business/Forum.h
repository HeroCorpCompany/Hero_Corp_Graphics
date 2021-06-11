#ifndef FORUM_H
#define FORUM_H

#include <vector>

#include "AbstractLocation.h"

class Forum : public AbstractLocation
{
public :
    Forum(int id, std::size_t x, std::size_t y);
};

#endif //FORUM_H
#ifndef FORUM_H
#define FORUM_H

#include "AbstractLocation.h"
#include "../tools/json.hpp"

using json = nlohmann::json;

class Forum : public AbstractLocation
{
public :
    Forum(std::size_t x, std::size_t y);

private :
    json m_chasseurs;
};

#endif //FORUM_H
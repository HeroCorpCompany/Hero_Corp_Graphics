#ifndef GUILD_H
#define GUILD_H

#include "AbstractLocation.h"
#include "../tools/json.hpp"

using json = nlohmann::json;

class Guild : public AbstractLocation
{
public :
    Guild(std::size_t x, std::size_t y);

private :
    json m_chasseurs;
};

#endif //GUILD_H
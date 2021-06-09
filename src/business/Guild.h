#ifndef GUILD_H
#define GUILD_H

#include "AbstractLocation.h"
#include "../tools/json.hpp"

using json = nlohmann::json;

class Guild : public AbstractLocation
{
public :
    Guild(int id, std::size_t x, std::size_t y);

private :
    json m_hunters;
    int golds;
    int pop;
};

#endif //GUILD_H
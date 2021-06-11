#ifndef GUILD_H
#define GUILD_H

#include "AbstractLocation.h"

class Guild : public AbstractLocation
{
public :
    Guild(int id, std::size_t x, std::size_t y, int golds);

private :
    int m_golds;
};

#endif //GUILD_H
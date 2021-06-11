#ifndef API_MANAGER_H
#define API_MANAGER_H

#include <SFML/Network.hpp>
#include <vector>
#include <iostream>

#include "../business/Forum.h"
#include "../business/Dungeon.h"
#include "../business/Guild.h"
#include "../business/Monster.h"
#include "../tools/json.hpp"

using json = nlohmann::json;

class ApiManager {
public :
    ApiManager();

    std::vector<AbstractLocation*> getLocations();
    std::vector<Hunter*> getHuntersInLocation(int idLocation);
    std::vector<Monster*> getMonstersInLocation(int idLocation);
    int getGuildGolds(int idLocation);

private :
    sf::Http m_http;
};

#endif //API_MANAGER_H
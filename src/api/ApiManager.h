#ifndef API_MANAGER_H
#define API_MANAGER_H

#include <SFML/Network.hpp>
#include <vector>

#include "../business/AbstractLocation.h"
#include "../business/Forum.h"
#include "../business/Dungeon.h"
#include "../business/Guild.h"
#include "../tools/json.hpp"

using json = nlohmann::json;

class ApiManager {
public :
    ApiManager();

    std::vector<AbstractLocation*> getLocations();

private :
    sf::Http m_http;
};

#endif //API_MANAGER_H
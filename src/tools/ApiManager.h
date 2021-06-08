#ifndef API_MANAGER_H
#define API_MANAGER_H

#include <SFML/Network.hpp>
#include <string>
#include <map>
#include <vector>

#include "json.hpp"

using json = nlohmann::json;

class ApiManager {
public :
    ApiManager();

    std::vector<std::map<std::string, std::string>*> getListLocation();
    std::vector<std::map<std::string, std::string>*> getHunters(int idLocation);
    std::vector<std::map<std::string, std::string>*> getMobs(int idLocation);

private :
    sf::Http m_http;
};

#endif //API_MANAGER_H
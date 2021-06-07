#ifndef API_MANAGER_H
#define API_MANAGER_H

#include <SFML/Network.hpp>
#include <string>
#include <map>

class ApiManager {
public :
    ApiManager();

private :
    std::map<std::string, int> stringToMap(std::string);
};

#endif //API_MANAGER_H
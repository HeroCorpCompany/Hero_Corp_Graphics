#include "ApiManager.h"

ApiManager::ApiManager()
{
    m_http.setHost("", 8000);
}

std::vector<AbstractLocation*> ApiManager::getLocations()
{
    std::vector<AbstractLocation*> locations;
    sf::Http::Request request;
    request.setMethod(sf::Http::Request::Get);
    request.setUri("/lieux");
    sf::Http::Response reponse = m_http.sendRequest(request);

    json rep = json::parse(reponse.getBody());

    for (std::size_t i = 0; i < rep.size(); ++i)
    {
        std::string type = rep[i]["type"];
        
        if (type == "Forum")
        {
            locations.push_back(new Forum(rep[i]["id"], rep[i]["x"], rep[i]["y"]));
        }
        else if (type == "Guilde")
        {
            locations.push_back(new Guild(rep[i]["id"], rep[i]["x"], rep[i]["y"]));
        }
        else if (type == "Donjon")
        {
            locations.push_back(new Dungeon(rep[i]["id"], rep[i]["x"], rep[i]["y"]));
        }
    }

    return locations;
}
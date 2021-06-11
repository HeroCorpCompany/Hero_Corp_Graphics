#include "ApiManager.h"

ApiManager::ApiManager()
{
    m_http.setHost("localhost", 8000);
}

std::vector<AbstractLocation*> ApiManager::getLocations()
{
    std::vector<AbstractLocation*> locations;
    sf::Http::Request request;
    request.setMethod(sf::Http::Request::Get);
    request.setUri("/lieux");
    sf::Http::Response response = m_http.sendRequest(request);

    if (response.getStatus() == sf::Http::Response::Ok)
    {
        json rep = json::parse(response.getBody());

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
    }

    return locations;
}

std::vector<Hunter*> ApiManager::getHuntersInLocation(int idLocation)
{
    std::vector<Hunter*> hunters;
    sf::Http::Request request;
    request.setMethod(sf::Http::Request::Get);
    request.setUri("/chasseurs/lieu/" + std::to_string(idLocation));
    sf::Http::Response response = m_http.sendRequest(request);

    if (response.getStatus() == sf::Http::Response::Ok)
    {
        json rep = json::parse(response.getBody());

        for (std::size_t i = 0; i < rep.size(); ++i)
        {
            std::string level = rep[i]["classe"];
            hunters.push_back(new Hunter(rep[i]["id"], rep[i]["idPosition"], level, rep[i]["argent"], rep[i]["age"]));
        }
    }

    return hunters;
}

std::vector<Monster*> ApiManager::getMonstersInLocation(int idLocation)
{
    std::vector<Monster*> monsters;
    sf::Http::Request request;
    request.setMethod(sf::Http::Request::Get);
    request.setUri("/monstres/" + std::to_string(idLocation));
    sf::Http::Response response = m_http.sendRequest(request);

    if (response.getStatus() == sf::Http::Response::Ok)
    {
        json rep = json::parse(response.getBody());

        for (std::size_t i = 0; i < rep.size(); ++i)
        {
            std::string level = rep[i]["classe"];
            monsters.push_back(new Monster(rep[i]["id"], rep[i]["idDonjon"], level));
        }
    }

    return monsters;
}

int ApiManager::getGuildGolds(int idLocation)
{
    int golds = 0;

    sf::Http::Request request;
    request.setMethod(sf::Http::Request::Get);
    request.setUri("/chasseurs/guilde/" + std::to_string(idLocation));
    sf::Http::Response response = m_http.sendRequest(request);

    if (response.getStatus() == sf::Http::Response::Ok)
    {
        json rep = json::parse(response.getBody());

        golds = rep["argent"];
    }

    return golds;
}
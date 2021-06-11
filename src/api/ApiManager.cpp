#include "ApiManager.h"
#include "../business/World.h"

ApiManager::ApiManager()
{
    m_http.setHost("localhost", 8000);
}

void ApiManager::updateWorld(World* world)
{
    sf::Http::Request request;
    request.setMethod(sf::Http::Request::Get);

    request.setUri("/all");
    sf::Clock clock;
    sf::Http::Response response = m_http.sendRequest(request);
    sf::Time time = clock.restart();
    std::cout << "Time : "<< time.asSeconds() << std::endl;

    if (response.getStatus() == sf::Http::Response::Ok)
    {
        json rep = json::parse(response.getBody());

        //UPDATE LIEUX

        std::vector<AbstractLocation*> locations;
        json lieux = rep["lieux"];
        json guildes = rep["guildes"];

        for (std::size_t i = 0; i < lieux.size(); ++i)
        {
            std::string type = lieux[i]["type"];

            if (type == "Forum")
            {
                locations.push_back(new class Forum(lieux[i]["id"], lieux[i]["x"], lieux[i]["y"]));
            }
            else if (type == "Guilde")
            {
                int golds;

                for (std::size_t j = 0; j < guildes.size(); ++j)
                {
                    if (guildes[j]["id"] == lieux[i]["id"])
                    {
                        golds = guildes[j]["argent"];
                    }
                }

                locations.push_back(new class Guild(lieux[i]["id"], lieux[i]["x"], lieux[i]["y"], golds));
            }
            else if (type == "Donjon")
            {
                locations.push_back(new class Dungeon(lieux[i]["id"], lieux[i]["x"], lieux[i]["y"]));
            }
        }

        world->setLocations(locations);

        //UPDATE CHASSEURS

        std::vector<Hunter*> hunters;
        json chasseurs = rep["chasseurs"];

        for (std::size_t i = 0; i < chasseurs.size(); ++i)
        {
            std::string level = chasseurs[i]["classe"];
            hunters.push_back(new Hunter(chasseurs[i]["id"], chasseurs[i]["idPosition"], level, chasseurs[i]["argent"], chasseurs[i]["age"]));
        }

        world->setHunters(hunters);

        //UPDATE MONSTRES

        std::vector<Monster*> monsters;
        json monstres = rep["monstres"];

        for (std::size_t i = 0; i < monstres.size(); ++i)
        {
            std::string level = monstres[i]["classe"];
            monsters.push_back(new Monster(monstres[i]["id"], monstres[i]["idDonjon"], level));
        }

        world->setMonsters(monsters);

        //UPDATE STATS

        int time, nbHunters, nbDungeons, nbGuilds;
        json stats = rep["stats"];

        time = stats["temps"];
        nbHunters = stats["nbChasseurs"];
        nbDungeons = stats["nbDonjons"];
        nbGuilds = stats["nbGuildes"];

        world->setStatistics(time, nbHunters, nbDungeons, nbGuilds);
    }
}
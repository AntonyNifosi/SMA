#include "Factory.hpp"

Factory::Factory()
{

}

std::array<std::array<Entitee*, 20>, 20> Factory::createAgents()
{

    Reader *r = Reader::getInstance("Config1.txt");
    std::string config = r->readConfig();
    std::array<std::array<Entitee*, 20>, 20> agents;

    for (int i = 0; i < config.size(); i++)
    {
        switch(config[i])
        {
            case 'A':
                agents[(i/20)][i % 20] = new Agressif((i / 20),(i % 20));
                break;

            case 'P':
                agents[(i/20)][i % 20] = new Passifish((i / 20),(i % 20));
                break;

            case 'R':
                agents[(i/20)][i % 20] = new Ressource((i / 20),(i % 20));
                break;
        }
    }

    return agents;
}
#include "Agent.hpp"
#include "Passifish.hpp"
#include "Plateau.hpp"

Passifish::Passifish() : Agent(0 , 0, 6)
{}

Passifish::Passifish(int x, int y) :
Agent(x, y, 6)
{}

Passifish::~Passifish()
{}

void Passifish::Afficher()
{
    std::cout << " P ";
}

std::string Passifish::JeSuis()
{
    return "Passifish";
}

bool Passifish::mort()
{
    return _time_no_eat > 12;
}

Cible_t Passifish::Selection(std::vector<Cible_t> cibles)
{
    std::vector<Cible_t>::iterator it;

    Cible_t c;
    c.distance = 9999;
    c.cible = nullptr;
    
    for(it = cibles.begin(); it != cibles.end(); it++ )
    {
        if((*it).cible->JeSuis() == "Ressource")
        {
            if(c.distance > (*it).distance && (c.cible == nullptr || c.cible->JeSuis() == "Ressource"))
            {
                c = (*it);
            }
        }
        else if ((*it).cible->JeSuis() == "Agressif")
        {
            if(Tuable((*it), cibles))
            {
                c = (*it);
            }
        }
    }

    return c;
}

bool Passifish::Tuable(Cible_t c, std::vector<Cible_t> cibles)
{
    std::vector<Cible_t>::iterator it;

    float avantage = 0;

    for(it = cibles.begin(); it != cibles.end(); it++ )
    {
        int distance = c.cible->getVector().distance((*it).cible->getVector());
        if(distance < 4 && distance > 0)
        {
            if((*it).cible->JeSuis() == "Agressif")
            {
                avantage -= 1 / (float)distance;
            }
            else if((*it).cible->JeSuis() == "Passifish")
            {
                avantage += 1 / (float)distance;
            }
        } 
    }

    return avantage >= 2;
}

void Passifish::Traitement(Plateau *p, Cible_t c)
{
    std::cout << "debut traitement" << std::endl;
    if (c.cible->JeSuis() == "Agressif")
    {
        p->Delete(c.cible);
    }
    else
    {
        Agent::manger(p, c.cible); 
        Agent::seReproduire(p);
        Agent::seReproduire(p);
    }
    std::cout << "fin traitement" << std::endl;
}
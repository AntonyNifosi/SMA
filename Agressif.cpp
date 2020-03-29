#include "Agressif.hpp"
#include "Plateau.hpp"

Agressif::Agressif() : Agent(0, 0, 4)
{}

Agressif::Agressif(int x, int y):
Agent(x, y, 4)
{}

Agressif::~Agressif()
{}

Cible_t Agressif::Selection(std::vector<Cible_t> cibles)
{
    std::vector<Cible_t>::iterator it;

    Cible_t c;
    c.distance = 9999;
    
    for(it = cibles.begin(); it != cibles.end(); it++ )
    {
        if((*it).cible->JeSuis() != AGRESSIF || Affame())
        {
            if(c.distance > (*it).distance)
            {
                c = (*it);
            }
        }
    }

    return c;
}

void Agressif::Traitement(Plateau *p, Cible_t c)
{
    EntiteeType cible = c.cible->JeSuis();
    Agent::manger(p, c.cible);
    if(cible != AGRESSIF)
    {
        reprod = (reprod + 1) % 2;
        if(reprod == 0)
        {
            Agent::seReproduire(p);
        }
    }
}

void Agressif::Afficher()
{
    std::cout << " A ";
}

bool Agressif::Affame()
{
    return _time_no_eat > 5;
}

EntiteeType Agressif::JeSuis()
{
    return AGRESSIF;
}

bool Agressif::mort()
{
    return _time_no_eat > 10;
}
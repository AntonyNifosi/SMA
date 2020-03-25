#include "Agressif.hpp"
#include "Plateau.hpp"

Agressif::Agressif() : Agent(0, 0, 4)
{}

Agressif::Agressif(int x, int y):
Agent(x, y, 4)
{}

Cible_t Agressif::Selection(std::vector<Cible_t> cibles)
{
    std::vector<Cible_t>::iterator it;

    Cible_t c;
    c.distance = 9999;
    
    for(it = cibles.begin(); it != cibles.end(); it++ )
    {
        if((*it).cible->JeSuis() != "Agressif" || Affame())
        {
            if(c.distance > (*it).distance)
            {
                c = (*it);
            }
        }
    }

    return c;
}

void Agressif::Traitement(Cible_t c)
{
    
}

void Agressif::Afficher()
{
    std::cout << " A ";
}

bool Agressif::Affame()
{
    return _time_no_eat > 5;
}

std::string Agressif::JeSuis()
{
    return "Agressif";
}

bool Agressif::mort()
{
    return _time_no_eat > 10;
}
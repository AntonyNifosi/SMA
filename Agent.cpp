#include "Agent.hpp"
#include "Plateau.hpp"
#include "Entitee.hpp"

Agent::Agent(int x, int y, int vision) : 
Entitee(x, y), _vision(vision), direction(0 ,0)
{}

Agent::~Agent()
{}

void Agent::update(Plateau* p)
{}

void Agent::move(Vector2 dir, Plateau* p)
{
    int newPosX = _pos.getX() + dir.getX();
    int newPosY = _pos.getY() + dir.getY();
    if(newPosX >= 0 && newPosX < TAILLE_PLATEAU && newPosY >= 0 && newPosY < TAILLE_PLATEAU)
    {
        if (p->recupCase(newPosX, newPosY) == nullptr)
        {
            p->Deplacer(this, dir);
        }
    }
}

std::vector<Cible_t> Agent::EnVue(Plateau* p)
{
    std::vector<Cible_t> Cibles;

    for(int i = _pos.getX() - _vision; i < _pos.getX() + _vision; i++)
    {
        if(i >= 0 && i < TAILLE_PLATEAU)
        {
            int distI = abs(_pos.getX() - i);
            for(int j = _pos.getY() - _vision + distI; j < _pos.getY() + _vision - distI; j++)
            {
                if( j >= 0 && j < TAILLE_PLATEAU && !(j == _pos.getY() && i == _pos.getX()))
                {
                    Entitee* e = p->recupCase(i, j); 
                    if(e != nullptr)
                    {
                        Cible_t c;
                        c.cible = e;
                        c.distance = abs(_pos.getX() - i) + abs(_pos.getY() - j);
                        Cibles.push_back(c);
                    }
                }
            }
        }
    }

    return Cibles;
}

void Agent::afficherCible(std::vector<Cible_t> cibles)
{
    std::vector<Cible_t>::iterator it;
    for(it = cibles.begin(); it != cibles.end(); it++ )
    {
        std::cout << (*it).cible->JeSuis() << " distance : " << (*it).distance << std::endl;
    }
    std::cout << std::endl;
}

void Agent::seReproduire(Plateau *p)
{
    Vector2 location = p->caseLibre(this);
    if (location.isValidPosition())
    {
        p->createAgent(AGRESSIF, location);
    }
    else
    {
        std::cout << "impossible de reproduire !" << std::endl;
    }
}

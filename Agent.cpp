#include "Agent.hpp"

Agent::Agent(int x, int y) : 
Entitee(x, y), direction(0 ,0)
{}

Agent::~Agent()
{}

void Agent::update(Plateau* p)
{
}

void Agent::move(Vector2 dir)
{

}

bool Agent::dead()
{
    return true;
}

std::vector<Cible_t> Agent::EnVue(Plateau* p)
{
    std::vector<Cible_t> Cibles;

    for(int i = posx - _vision; i < posx + _vision; i++)
    {
        if(i >= 0 && i < TAILLE_PLATEAU)
        {
            for(int j = posy - _vision + abs(posx - i); j < posy - _vision + (abs(posx - i)); i++)
            {
                if( j >= 0 && j < TAILLE_PLATEAU)
                {
                    Entitee e = p->recupCase(i, j); 
                    if(e != nullptr)
                    {
                        Cible_t c;
                        c.cible = e;
                        c.distance = abs(posx - i) + abs(posy - j);
                        Cibles.pushback(c);
                    }
                }
            }
        }
    }

    return Cibles;
}
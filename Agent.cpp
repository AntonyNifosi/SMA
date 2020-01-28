#include "Agent.hpp"

Agent::Agent(int x, int y) : 
Entitee(x, y), direction(0 ,0)
{}

Agent::~Agent()
{}

void Agent::update(Plateau* p)
{
    std::cout << "WE CA BUG" << std::endl;
}

void Agent::move(Vector2 dir, Plateau* p)
{
    std::cout << dir.getX() << " / " << dir.getY() << std::endl;
    if (p->recupCase(_posx + dir.getX(), _posy + dir.getY()) == nullptr)
    {
        std::cout << "On deplace !" << std::endl;
        p->Deplacer(this, dir);
    }
}

bool Agent::dead()
{
    return true;
}

std::vector<Cible_t> Agent::EnVue(Plateau* p)
{
    std::vector<Cible_t> Cibles;

    for(int i = _posx - _vision; i < _posx + _vision; i++)
    {
        if(i >= 0 && i < TAILLE_PLATEAU)
        {
            for(int j = _posy - _vision + abs(_posx - i); j < _posy - _vision + (abs(_posx - i)); i++)
            {
                if( j >= 0 && j < TAILLE_PLATEAU)
                {
                    Entitee* e = p->recupCase(i, j); 
                    if(e != nullptr)
                    {
                        Cible_t c;
                        c.cible = e;
                        c.distance = abs(_posx - i) + abs(_posy - j);
                        Cibles.push_back(c);
                    }
                }
            }
        }
    }

    return Cibles;
}
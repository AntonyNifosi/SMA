#include "Agent.hpp"

Agent::Agent(int x, int y) : 
Entitee(x, y), direction(0 ,0)
{}

Agent::~Agent()
{}

void Agent::update(Plateau* p)
{

}

void Agent::move(Vector2 dir, Plateau* p)
{
    if (p->recupCase(_posx + dir.getX(), _posy + dir.getY()) == nullptr)
    {
        if (_posx + dir.getX() < TAILLE_PLATEAU && _posx >= 0)
        {
            _posx += dir.getX();
        }
        if (_posy + dir.getY() < TAILLE_PLATEAU && _posy >= 0)
        {
            _posy += dir.getY();
        }
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
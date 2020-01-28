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

    return Cibles;
}
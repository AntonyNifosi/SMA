#include "Agent.hpp"

Agent::Agent(int x, int y) : 
Entitee(x, y), direction(0 ,0)
{}

Agent::~Agent()
{}

void Agent::update(Plateau* p)
{
    p->recupCase(1, 2);
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

    return Cibles;
}
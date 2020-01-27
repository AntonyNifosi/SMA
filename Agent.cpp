#include "Agent.hpp"

Agent::Agent(int x, int y) : 
Entitee(x, y)
{}

Agent::~Agent()
{}

void Agent::update(Plateau* p)
{
    p->recupCase(1, 2);
}

void Agent::move()
{}

bool Agent::dead()
{
    return true;
}

std::vector<Cible_t> Agent::EnVue(Plateau* p)
{
    std::vector<Cible_t> Cibles;

    return Cibles;
}
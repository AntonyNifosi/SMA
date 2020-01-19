#include "Agent.hpp"

Agent::Agent(int x, int y) : 
Entitee(x, y)
{}

Agent::~Agent()
{}

void Agent::update()
{}

void Agent::move()
{}

bool Agent::dead()
{
    return true;
}
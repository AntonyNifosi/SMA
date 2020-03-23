#include "Agent.hpp"
#include "Passifish.hpp"

Passifish::Passifish() : Agent(0 , 0, 6)
{}

Passifish::Passifish(int x, int y) :
Agent(x, y, 6)
{}

void Passifish::Afficher()
{
    std::cout << " P ";
}

std::string Passifish::JeSuis()
{
    return "Passifish";
}

bool Passifish::Mort()
{
    return _time_no_eat > 12;
}

void Passifish::update(Plateau* p)
{
    int new_x = (generateur() % 2) * 2 - 1;
    int new_y = (generateur() % 2) * 2 - 1;

    Agent::move(Vector2(new_x, new_y), p);
}
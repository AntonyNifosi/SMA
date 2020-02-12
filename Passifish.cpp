#include "Passifish.hpp"

Passifish::Passifish() : Agent(0 ,0)
{
    _vision = 3;
}

Passifish::Passifish(int x, int y) :
Agent(x, y)
{
    _vision = 3;
}

void Passifish::Afficher()
{
    std::cout << " P ";
}

std::string Passifish::JeSuis()
{
    return "Passifish";
}

void Passifish::update(Plateau* p)
{
    int new_x = (generateur() % 2) * 2 - 1;
    int new_y = (generateur() % 2) * 2 - 1;

    Agent::move(Vector2(new_x, new_y), p);
}
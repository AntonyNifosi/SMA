#include "Passifish.hpp"

Passifish::Passifish(int x, int y) :
Agent(x, y)
{}

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
    int new_x = generateur() % 1 * 2 - 1;
    int new_y = generateur() % 1 * 2 - 1;

    Agent::move(Vector2(new_x, new_y), p);
}
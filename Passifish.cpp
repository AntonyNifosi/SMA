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
    std::cout << "On update Passif" << std::endl;
    int new_x = (generateur() % 2) * 2 - 1;
    int new_y = (generateur() % 2) * 2 - 1;

    Agent::move(Vector2(new_x, new_y), p);
}
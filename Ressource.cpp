#include "Ressource.hpp"

Ressource::Ressource(int x, int y) :
Entitee(x, y)
{
}

void Ressource::Afficher()
{
    std::cout << "R ";
}

std::string Ressource::JeSuis()
{
    return "Ressource";
}
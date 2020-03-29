#include "Ressource.hpp"

Ressource::Ressource() : Entitee(0, 0)
{
}

Ressource::Ressource(int x, int y) :
Entitee(x, y)
{
}

Ressource::~Ressource()
{}

void Ressource::Afficher()
{
    std::cout << " R ";
}

EntiteeType Ressource::JeSuis()
{
    return RESSOURCE;
}
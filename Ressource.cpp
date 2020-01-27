#include "Ressource.hpp"

Ressource::Ressource(int x, int y) :
Entitee(x, y)
{
}

Ressource::~Ressource()
{}

void Ressource::Afficher()
{
    std::cout << "R ";
}

std::string Ressource::JeSuis()
{
    return "Ressource";
}
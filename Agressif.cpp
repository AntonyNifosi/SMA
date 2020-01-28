#include "Agressif.hpp"

Agressif::Agressif(int x, int y):
Agent(x, y)
{}

void Agressif::update(Plateau *p)
{
    std::cout << "On update un Agressif !" << std::endl;
}

void Agressif::Afficher()
{
    std::cout << " A ";
}

std::string Agressif::JeSuis()
{
    return "Agressif";
}
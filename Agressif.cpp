#include "Agressif.hpp"

Agressif::Agressif(int x, int y) : Agent(x, y)
{

}

void Agressif::Afficher()
{
    std::cout << "A";
}

std::string Agressif::JeSuis()
{
    return "Agressif";
}
#include "Passifish.hpp"

Passifish::Passifish(int x, int y) : Agent(x, y)
{

}

void Passifish::Afficher()
{
    std::cout << "P ";
}

std::string Passifish::JeSuis()
{
    return "Passifish";
}
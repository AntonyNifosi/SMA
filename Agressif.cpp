#include "Agressif.hpp"

Agressif::Agressif() : Agent(0, 0)
{
    _vision = 4;
}

Agressif::Agressif(int x, int y):
Agent(x, y)
{
    _vision = 4;
}

void Agressif::update(Plateau *p)
{
    int new_x = (generateur() % 2) * 2 - 1;
    int new_y = (generateur() % 2) * 2 - 1;

    std::vector<Cible_t> cibles = EnVue(p);
    afficherCible(cibles);

    Agent::move(Vector2(new_x, new_y), p);
}

void Agressif::Afficher()
{
    std::cout << " A ";
}

std::string Agressif::JeSuis()
{
    return "Agressif";
}
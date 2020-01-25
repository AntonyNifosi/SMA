#include "Entitee.hpp"

std::mt19937 generateur(666);

Entitee::Entitee(int x, int y) :
_posx(x),
_posy(y)
{}

Entitee::~Entitee()
{}

void Entitee::Afficher()
{}

int Entitee::getPosx()
{
    return _posx;
}

int Entitee::getPosy()
{
    return _posy;
}

void Entitee::setPos(int x, int y)
{
    _posx = x;
    _posy = y;
}
#include "Entitee.hpp"

std::mt19937 generateur(666);

Entitee::Entitee(int x, int y) :
_pos(x, y)
{}

Entitee::~Entitee()
{}

void Entitee::Afficher()
{}

int Entitee::getX()
{
    return _pos.getX();
}

int Entitee::getY()
{
    return _pos.getY();
}

void Entitee::setPos(Vector2 pos)
{
    _pos.setX(pos.getX());
    _pos.setY(pos.getY());
}

Vector2 Entitee::getVector()
{
    return _pos;
}

bool Entitee::isAvailable()
{
    return _available;
}

void Entitee::setAvailable(bool available)
{
    _available = available;
}
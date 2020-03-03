#include "Vector2.hpp"

Vector2::Vector2(int x, int y) : _x(x), _y(y)
{}

int Vector2::getX()
{
    return _x;
}

int Vector2::getY()
{
    return _y;
}

void Vector2::setX(int x)
{
    _x = x;
}

void Vector2::setY(int y)
{
    _y = y;
}

bool Vector2::isValidPosition()
{
    if (_x >= 0 && _y >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
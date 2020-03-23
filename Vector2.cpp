#include "Vector2.hpp"

Vector2::Vector2(int x, int y) : _x(x), _y(y)
{}

Vector2::Vector2(Vector2 const& v) :
_x(v.getX()),
_y(v.getY())
{}

int Vector2::getX() const
{
    return _x;
}

int Vector2::getY() const
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

int Vector2::distance(Vector2 v2)
{
    return abs(_x - v2.getX()) + abs(_y - v2.getY());
}

bool operator!=(Vector2 const& v1, Vector2 const& v2)
{
    return v1.getX() != v2.getX() || v1.getY() != v2.getY();
}

bool operator==(Vector2 const& v1, Vector2 const& v2)
{
    return v1.getX() == v2.getX() && v1.getY() == v2.getY();
}

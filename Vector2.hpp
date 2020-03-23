#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>

class Vector2
{
    private :
        int _x;
        int _y;

    public :
        Vector2(int x, int y);
        Vector2(Vector2 const& v);
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
        bool isValidPosition();
        int distance(Vector2 v2);
};

bool operator!=(Vector2 const& v1, Vector2 const& v2);
bool operator==(Vector2 const& v1, Vector2 const& v2);

#endif
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2
{
    private :
        int _x;
        int _y;

    public :
        Vector2(int x, int y);
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
};



#endif
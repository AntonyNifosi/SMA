#ifndef ENTITEE_HPP
#define ENTITEE_HPP

#include <string>
#include <iostream>
#include <random>
#include "Vector2.hpp"

extern std::mt19937 generateur;

class Entitee
{
    protected:
        int _posx;
        int _posy;

    public:
        Entitee(int x, int y);
        virtual ~Entitee();
        int getPosx();
        int getPosy();
        void setPos(Vector2 pos);
        virtual void Afficher() = 0;
        virtual std::string JeSuis() = 0;
};

#endif
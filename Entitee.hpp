#ifndef ENTITEE_HPP
#define ENTITEE_HPP

#include <string>
#include <iostream>
#include <random>

extern std::mt19937 generateur;

class Entitee
{
    protected:
        int _posx;
        int _posy;

    public:
        Entitee(int x, int y);
        ~Entitee();
        int getPosx();
        int getPosy();
        void setPos(int x, int y);
        virtual void Afficher() = 0;
        virtual std::string JeSuis() = 0;
};

#endif
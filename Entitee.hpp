#ifndef ENTITEE_HPP
#define ENTITEE_HPP

#include <string>
#include <iostream>
#include <random>

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
        void Afficher();
        std::string JeSuis();
};

#endif
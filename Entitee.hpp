#ifndef ENTITEE_HPP
#define ENTITEE_HPP

#include <string>
#include <iostream>
#include <random>

#include "Vector2.hpp"

extern std::mt19937 generateur;

enum EntiteeType
{
	AGRESSIF, PASSIFISH, RESSOURCE
};

class Entitee
{
    protected:
        Vector2 _pos;
		bool _available = true;

    public:
        Entitee(int x, int y);
        virtual ~Entitee();
        int getX();
        int getY();
        void setPos(Vector2 pos);
        virtual void Afficher() = 0;
        virtual EntiteeType JeSuis() = 0;
        Vector2 getVector();
        bool isAvailable();
        void setAvailable(bool available);
};

#endif
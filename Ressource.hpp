#ifndef RESSOURCE_HPP
#define RESSOURCE_HPP

#include "Agent.hpp"

class Ressource : public Entitee
{
    public:
        Ressource();
        Ressource(int x, int y);
        ~Ressource();
        void Afficher();
        EntiteeType JeSuis();
};

#endif
#ifndef RESSOURCE_HPP
#define RESSOURCE_HPP

#include "Entitee.hpp"

class Ressource : public Entitee
{
    public:
        Ressource(int x, int y);
        ~Ressource();
        void Afficher();
        std::string JeSuis();
};

#endif
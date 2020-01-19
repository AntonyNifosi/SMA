#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>
#include "Entitee.hpp"
#include "Agent.hpp"

#define TAILLE_PLATEAU 20

class Plateau
{
    private:
        Entitee* _plateau[20][20];
        std::vector <Agent*> _agents;

    public:
        Plateau();
        Plateau(std::string Nom);
        ~Plateau();
        void Afficher();
        void Update();
};

#endif
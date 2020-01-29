#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>
#include <array>
#include <fstream>

#define TAILLE_PLATEAU 20

#include "Entitee.hpp"
#include "Agent.hpp"

class Agent;

class Plateau
{
    private:
        std::array<std::array<Entitee*, TAILLE_PLATEAU>, TAILLE_PLATEAU> _plateau;
        std::vector <Agent*> _agents;

    public:
        Plateau();
        Plateau(std::string nom);
        ~Plateau();
        void Afficher();
        void Update();
        void Ajouter(Entitee* e, int x, int y);
        void Ajouter(Agent* e, int x, int y);
        void Delete(int x, int y);
        Entitee* recupCase(int x, int y);
        void Deplacer(Entitee* e, Vector2 v);
};

#endif
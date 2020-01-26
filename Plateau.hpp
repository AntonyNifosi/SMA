#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>
#include <array>
#include <fstream>
#include "Agent.hpp"
#include "Passifish.hpp"
#include "Agressif.hpp"
#include "Ressource.hpp"

#define TAILLE_PLATEAU 20

class Plateau
{
    private:
        std::array<std::array<Entitee*, TAILLE_PLATEAU>, TAILLE_PLATEAU> _plateau;
        std::vector <Agent*> _agents;

    public:
        Plateau();
        Plateau(std::string Nom);
        ~Plateau();
        void Afficher();
        void Update();
        void Ajouter(Entitee* e, int x, int y);
        void Ajouter(Agent* e, int x, int y);
        void Delete(int x, int y);
        Entitee* recupCase(int x, int y);
        void Deplacer(int x, int y, int dx, int dy);
};

#endif
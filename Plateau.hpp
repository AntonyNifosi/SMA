#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>
#include <array>
#include <fstream>

#define TAILLE_PLATEAU 20
#include "Entitee.hpp"
#include "Factory.hpp"


class Agent;

class Plateau
{
    private:
        std::array<std::array<Entitee*, TAILLE_PLATEAU>, TAILLE_PLATEAU> _plateau;
        std::vector <Agent*> _agents;
        std::vector <Agent*> _agentsCur;
        Factory f;

    public:
        Plateau();
        Plateau(std::string nom);
        ~Plateau();
        void Afficher();
        void Update();
        void Ajouter(Entitee* e, int x, int y);
        void createAgent(EntiteeType type, Vector2 position);
        void Ajouter(Agent* e, int x, int y);
        void Delete(Entitee *e);
        Entitee* recupCase(int x, int y);
        void Deplacer(Entitee* e, Vector2 v);
        Vector2 caseLibre(Entitee* e);
        Vector2 PathFinding(Vector2 depart, Vector2 arrive);
        std::array<std::array<int, TAILLE_PLATEAU>, TAILLE_PLATEAU> CreerChemin(Vector2 depart, Vector2 arrive);
        Vector2 Recup_Chemin(Vector2 depart, Vector2 arrive, std::array<std::array<int, TAILLE_PLATEAU>, TAILLE_PLATEAU> _matrice);
        void FreeDead();
};

#endif
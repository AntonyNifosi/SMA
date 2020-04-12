/**
 * @file Plateau.hpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Interface de la classe Plateau
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */


#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>
#include <array>
#include <algorithm>

/**
 * @brief Taille du plateau 
 */
#define TAILLE_PLATEAU 20
#include "Factory.hpp"


class Agent;

/**
 * @brief Plateau sur lequel évolue des Agent 
 */
class Plateau
{
    private:
        ///Matrice des Entitee présente dans le Plateau actuellement
        std::array<std::array<Entitee*, TAILLE_PLATEAU>, TAILLE_PLATEAU> _plateau;
        ///Vector d'Agent contenant tout les Agent présent actuellement sur le _plateau
        std::vector <Agent*> _agents;
        ///Copie de _agents pour ne traiter que les Agent actuel à chaque update
        std::vector <Agent*> _agentsCur;
        ///Factory créant les différentes Entitee 
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
        Vector2 Recup_Chemin(Vector2 depart, Vector2 arrive, std::array<std::array<int, TAILLE_PLATEAU>, TAILLE_PLATEAU> _matrice);
        void FreeDead();
        void SpawnRessource();
};

#endif
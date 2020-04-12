/**
 * @file Passifish.hpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Interface de la classe Passifish
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#ifndef PASSIFISH_HPP
#define PASSIFISH_HPP

#include "Agent.hpp"

/**
 * @brief Agent de type Passifish plus faible que l'agressif il favorise les Ressource.
 * 		  Cependant si les Passifish sont assez nombreux ils convergeront vers les autres Agent pour les exterminer
 */
class Passifish : public Agent
{
    public:
        Passifish();
        Passifish(int x, int y);
        ~Passifish();
		bool mort();
        void Afficher();
        EntiteeType JeSuis();
		Cible_t Selection(std::vector<Cible_t> cibles);
        bool Tuable(Cible_t c, std::vector<Cible_t> cibles);
        void Traitement(Plateau *p, Cible_t c);
};

#endif
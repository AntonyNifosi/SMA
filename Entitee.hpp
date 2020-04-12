/**
 * @file Entitee.hpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Interface de la classe Entitee
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#ifndef ENTITEE_HPP
#define ENTITEE_HPP

#include <string>
#include <iostream>
#include <random>

#include "Vector2.hpp"

/**
 * @brief Générateur de nombre aléatoire
 *        Utilise la méthode mersenne twister
 */
extern std::mt19937 generateur;

/** 
 * @brief Enum des noms des Entitee possibles
*/
enum EntiteeType
{
	AGRESSIF, PASSIFISH, RESSOURCE
};

/**
 * @brief Classe mère des différentes Entitee
 */
class Entitee
{
    protected:
        /// Position actuel de l'Entitee
        Vector2 _pos;
        /// Statut de l'Entitee 
		bool _mort = false;

    public:
        Entitee(int x, int y);
        virtual ~Entitee();
        int getX();
        int getY();
        void setPos(Vector2 pos);
        /**
         * @brief Affichage de l'Entitee
         */
        virtual void Afficher() = 0;
        /**
         * @brief Renvoi la classe de l'Entitee
         * 
         * @return EntiteeType
         */
        virtual EntiteeType JeSuis() = 0;
        Vector2 getVector();
        bool isMort();
        void setMort(bool available);
};

#endif
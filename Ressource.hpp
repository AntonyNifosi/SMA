/**
 * @file Ressource.hpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Interface de la classe Ressource
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#ifndef RESSOURCE_HPP
#define RESSOURCE_HPP

#include "Entitee.hpp"

/**
 * @brief Ressource que se dispute les différents Agent
 */
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
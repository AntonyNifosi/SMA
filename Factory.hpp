/**
 * @file Factory.hpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Interface de la classe Factory
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Passifish.hpp"
#include "Agressif.hpp"
#include "Ressource.hpp"

/**
 * @brief Crée différent type d'Entitee selon les fonctions appelées
 */
class Factory
{
    public :
        Factory();
        Passifish* createPassifish();
        Agressif* createAgressif();
        Ressource* createRessource();
};

#endif
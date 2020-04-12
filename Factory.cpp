/**
 * @file Factory.cpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Implémentation des fonctions relatives à la classe Factory
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#include "Factory.hpp"

/**
 * @brief Constructeur de la classe Factory
 * 
 */
Factory::Factory()
{}

/**
 * @brief Crée un Passifish
 * 
 * @return Passifish* pointeur sur le Passifish créée
 */
Passifish* Factory::createPassifish()
{
    Passifish* p = new Passifish();
    return p;
}   

/**
 * @brief Crée un Agressif
 * 
 * @return Agressif* pointeur sur le Agressif créée
 */
Agressif* Factory::createAgressif()
{
    Agressif* a = new Agressif();
    return a;
}

/**
 * @brief Crée un Ressource
 * 
 * @return Ressource* pointeur sur le Ressource créée
 */
Ressource* Factory::createRessource()
{
    Ressource* r = new Ressource();
    return r;
}
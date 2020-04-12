/**
 * @file Ressource.cpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Implémentation des fonctions relatives à la classe Ressource
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#include "Ressource.hpp"

/**
 * @brief Constructeur de la classe Ressource
 */
Ressource::Ressource() : Entitee(0, 0)
{
}

/**
 * @brief Constructeur de la classe Ressource
 * 
 * @param x position x de la Ressource
 * @param y position y de la Ressource
 */
Ressource::Ressource(int x, int y) :
Entitee(x, y)
{
}


/**
 * @brief Destructeur de la classe Ressource
 * 
 */
Ressource::~Ressource()
{}

/**
 * @brief Affichage de Ressource
 * 
 */
void Ressource::Afficher()
{
    std::cout << " R ";
}

/**
 * @brief Renvoi la classe de l'Entitee
 * 
 * @return EntiteeType l'Entitee est une Ressource
 */
EntiteeType Ressource::JeSuis()
{
    return RESSOURCE;
}
/**
 * @file Agressif.cpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Implémentation des fonctions relatives à la classe Agressif
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#include "Agressif.hpp"
#include "Plateau.hpp"

/**
 * @brief Constructeur de la classe Agressif
 */
Agressif::Agressif() : Agent(0, 0, 4)
{}

/**
 * @brief Constructeur de la classe Agressif
 * 
 * @param x position x de la Agressif
 * @param y position y de la Agressif
 */
Agressif::Agressif(int x, int y):
Agent(x, y, 4)
{}

/**
 * @brief Destructeur de la classe Agressif
 * 
 */
Agressif::~Agressif()
{}

/**
 * @brief Selection de la Cible à partir d'un vecteur contenant toutes les Cible potentiels
 * 
 * @details Les Agressif vont en priorité séléctionner les Cible les plus proche d'eux dans leur champ de vision.
 *          Après un certain nombre de tour sans manger les autres Agressif deviennent des Cible séléctionnable
 * 
 * @param cibles vecteur contenant les Cible dans le champ de vision de l'Agressif
 * @return Cible_t la Cible séléctionnée
 */
Cible_t Agressif::Selection(std::vector<Cible_t> cibles)
{
    std::vector<Cible_t>::iterator it;

    Cible_t c;
    c.distance = 9999;
    
    for(it = cibles.begin(); it != cibles.end(); it++ )
    {
        if((*it).cible->JeSuis() != AGRESSIF || Affame())
        {
            if(c.distance > (*it).distance)
            {
                c = (*it);
            }
        }
    }

    return c;
}

/**
 * @brief Traitement de la Cible séléctionné lorsque l'Agressif est à coté d'elle.
 * 
 * @param p Plateau sur lequel évolue l'Agressif
 * @param c Cible à traiter
 */
void Agressif::Traitement(Plateau *p, Cible_t c)
{
    EntiteeType cible = c.cible->JeSuis();
    Agent::manger(p, c.cible);
    if(cible != AGRESSIF)
    {
        reprod = (reprod + 1) % 2;
        if(reprod == 0)
        {
            Agent::seReproduire(p);
        }
    }
}

/**
 * @brief Affichage de l'Agressif
 * 
 */
void Agressif::Afficher()
{
    std::cout << " A ";
}

/**
 * @brief Renvoi si l'agressif est affamé ou non, si oui alors il deviens carnivore 
 * 
 * @return true L'agressif est affame
 * @return false sinon
 */
bool Agressif::Affame()
{
    return _time_no_eat > 5;
}

/**
 * @brief Renvoi la classe de l'Entitee
 * 
 * @return EntiteeType l'Entitee est une Ressource
 */
EntiteeType Agressif::JeSuis()
{
    return AGRESSIF;
}

/**
 * @brief Mort de l'Agressif après un certain nombre de tour sans manger
 * 
 * @return true si l'Agressif est mort
 * @return false sinon
 */
bool Agressif::mort()
{
    return _time_no_eat > 10;
}
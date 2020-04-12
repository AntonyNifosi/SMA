/**
 * @file Passifish.cpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Implémentation des fonctions relatives à la classe Passifish
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#include "Passifish.hpp"
#include "Plateau.hpp"

/**
 * @brief Constructeur de la classe Passifish
 */
Passifish::Passifish() : Agent(0, 0, 6)
{}

/**
 * @brief Constructeur de la classe Passifish
 * 
 * @param x position x de la Passifish
 * @param y position y de la Passifish
 */
Passifish::Passifish(int x, int y) :
Agent(x, y, 6)
{}

/**
 * @brief Destructeur de la classe Passifish
 * 
 */
Passifish::~Passifish()
{}

/**
 * @brief Selection de la Cible à partir d'un vecteur contenant toutes les Cible potentiels
 * 
 * @details Les Passifish vont par défaut séléctionner les Ressource les plus proche.
 *          Cependant si ils sont assez nombreux pour vaincre un Agressif ils iront tuer l'Agressif en priorité
 * 
 * @param cibles vecteur contenant les Cible dans le champ de vision du Passifish
 * @return Cible_t la Cible séléctionnée
 */
Cible_t Passifish::Selection(std::vector<Cible_t> cibles)
{
    std::vector<Cible_t>::iterator it;

    Cible_t c;
    c.distance = 9999;
    c.cible = nullptr;
    
    for(it = cibles.begin(); it != cibles.end(); it++ )
    {
        if((*it).cible->JeSuis() == RESSOURCE)
        {
            if(c.distance > (*it).distance && (c.cible == nullptr || c.cible->JeSuis() == RESSOURCE))
            {
                c = (*it);
            }
        }
        else if ((*it).cible->JeSuis() == AGRESSIF)
        {
            if(Tuable((*it), cibles))
            {
                c = (*it);
            }
        }
    }

    return c;
}

/**
 * @brief Indique si les Passifish sont assez nombreux pour tuer un Agressif
 * 
 * @param c un Agressif dans le champ de vision
 * @param cibles Le vecteur des autres Entitee dans le champ de vision
 * @return true Les Passifish peuvent tuer l'Agressif
 * @return false Les Passifish sont trop peu nombreux
 */
bool Passifish::Tuable(Cible_t c, std::vector<Cible_t> cibles)
{
    std::vector<Cible_t>::iterator it;

    float avantage = 0;

    for(it = cibles.begin(); it != cibles.end(); it++ )
    {
        int distance = c.cible->getVector().distance((*it).cible->getVector());
        if(distance < 4 && distance > 0)
        {
            if((*it).cible->JeSuis() == AGRESSIF)
            {
                avantage -= 1 / (float)distance;
            }
            else if((*it).cible->JeSuis() == PASSIFISH)
            {
                avantage += 1 / (float)distance;
            }
        } 
    }

    return avantage >= 2;
}

/**
 * @brief Traitement de la Cible séléctionné lorsque le Passifish est à coté d'elle.
 * 
 * @param p Plateau sur lequel évolue le Passifish
 * @param c Cible à traiter
 */
void Passifish::Traitement(Plateau *p, Cible_t c)
{
    if (c.cible->JeSuis() == AGRESSIF)
    {
        p->Delete(c.cible);
    }
    else
    {
        Agent::manger(p, c.cible); 
        Agent::seReproduire(p);
        Agent::seReproduire(p);
    }
}

/**
 * @brief Affichage du Passifish
 * 
 */
void Passifish::Afficher()
{
    std::cout << " P ";
}

/**
 * @brief Renvoi la classe de l'Entitee
 * 
 * @return EntiteeType l'Entitee est un Passifish
 */
EntiteeType Passifish::JeSuis()
{
    return PASSIFISH;
}

/**
 * @brief Mort du Passifish après un certain nombre de tour sans manger
 * 
 * @return true si le Passifish est mort
 * @return false sinon
 */
bool Passifish::mort()
{
    return _time_no_eat > 12;
}

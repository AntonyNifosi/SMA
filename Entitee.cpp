/**
 * @file Entitee.cpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Implémentation des fonctions relatives à la classe Entitee
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */
#include "Entitee.hpp"

/**
 * @brief Initialisation du generateur
 * 
 */
std::mt19937 generateur(630);

/**
 * @brief Constructeur de la classe Entitee
 * 
 * @param x position x de l'Entitee
 * @param y position y de l'Entitee
 */
Entitee::Entitee(int x, int y) :
_pos(x, y)
{}

/** 
 * @brief Destructeur de la classe Entitee
*/
Entitee::~Entitee()
{}

/**
 * @brief Récupère la coordonée X de l'Entitee
 * 
 * @return int La coordonée X
 */
int Entitee::getX()
{
    return _pos.getX();
}

/**
 * @brief Récupère la coordonée Y de l'Entitee
 * 
 * @return int La coordonée Y
 */
int Entitee::getY()
{
    return _pos.getY();
}

/**
 * @brief Setter de _pos
 * 
 * @param pos nouvelle valeur de _pos
 */
void Entitee::setPos(Vector2 pos)
{
    _pos.setX(pos.getX());
    _pos.setY(pos.getY());
}

/**
 * @brief Récupère le vecteur contenant la position actuel de l'Entitee
 * 
 * @return Vector2 vecteur 
 */
Vector2 Entitee::getVector()
{
    return _pos;
}

/**
 * @brief Getter de _mort
 * 
 * @return true si l'Entitee est mort
 * @return false dans le cas contraire
 */
bool Entitee::isMort()
{
    return _mort;
}

/**
 * @brief Setter de _mort
 * 
 * @param available nouvelle valeur de _mort
 */
void Entitee::setMort(bool available)
{
    _mort = available;
}
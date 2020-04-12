/**
 * @file Vector2.cpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Implémentation des fonctions relatives à la classe Vector2
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */
#include "Vector2.hpp"

/**
 * @brief Constructeur de la classe Vector2
 * 
 * @param x position x du Vector2
 * @param y position y de Vector2
 */
Vector2::Vector2(int x, int y) : _x(x), _y(y)
{}

/**
 * @brief Constructeur par copie de la classe Vector2
 * 
 * @param v Vector2 à copier
 */
Vector2::Vector2(Vector2 const& v) :
_x(v.getX()),
_y(v.getY())
{}

/**
 * @brief Getter de _x
 * 
 * @return int la valeur de _x
 */
int Vector2::getX() const
{
    return _x;
}

/**
 * @brief Getter de _y
 * 
 * @return int la valeur de _y
 */
int Vector2::getY() const
{
    return _y;
}

/**
 * @brief Setter de _x
 * 
 * @param x nouvelle valeur de x
 */
void Vector2::setX(int x)
{
    _x = x;
}

/**
 * @brief Setter de _y
 * 
 * @param y nouvelle valeur de y
 */
void Vector2::setY(int y)
{
    _y = y;
}

/**
 * @brief Vérifie que les coordonnées du Vector2 sont supérieurs à 0
 * 
 * @return true la position est valide
 * @return false la position est invalide
 */
bool Vector2::isValidPosition()
{
    if (_x >= 0 && _y >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

/**
 * @brief Calcule la distance entre deux Vector2
 * 
 * @param v2 Vector2 avec lequelle faire la conparaison
 * @return int distance entre les deux Vector2
 */
int Vector2::distance(Vector2 v2)
{
    return abs(_x - v2.getX()) + abs(_y - v2.getY());
}

/**
 * @brief Opérateur != pour deux Vector2
 * 
 * @param v1  
 * @param v2 
 * @return true si les Vector2 sont différents
 * @return false sinon
 */
bool operator!=(Vector2 const& v1, Vector2 const& v2)
{
    return v1.getX() != v2.getX() || v1.getY() != v2.getY();
}

/**
 * @brief Opérateur == pour deux Vector2
 * 
 * @param v1 
 * @param v2 
 * @return true si les Vector2 sont identiques
 * @return false sinon
 */
bool operator==(Vector2 const& v1, Vector2 const& v2)
{
    return v1.getX() == v2.getX() && v1.getY() == v2.getY();
}

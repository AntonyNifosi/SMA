/**
 * @file Vector2.hpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Interface de la classe Vector2
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>

/**
 * @brief Vecteur à deux dimensions stockant une position x et y 
 */
class Vector2
{
    private :
        /// Valeur x du Vector2
        int _x;
        /// Valeur y du Vector2
        int _y;

    public :
        Vector2(int x, int y);
        Vector2(Vector2 const& v);
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
        bool isValidPosition();
        int distance(Vector2 v2);
};

bool operator!=(Vector2 const& v1, Vector2 const& v2);
bool operator==(Vector2 const& v1, Vector2 const& v2);

#endif
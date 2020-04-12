/**
 * @file Interface.cpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Interface de la simulation
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#include "Plateau.hpp"

/**
 * Nombre de tours de la simulation
 */
#define NB_TOURS 100

/**
 * Nombre de ressource apparaissant sur le Plateau chaque tour
 */
#define NB_RESSOURCE_TOUR 10

#include <chrono>
#include <thread>

/**
 * @brief Programme principale de la simulation crée le Plateau au départ puis appele les fonctions nécesaires à chaque tour de la simulation
 * 
 * @return int Code d'erreur lors du programme principale
 */
int main()
{
    Plateau p;
    std::cout << "=============== Tour 0 ===============" << std::endl;
    
    p.Afficher();
    
    for(int i = 0; i < NB_TOURS; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        system("clear");
        std::cout << "=============== Tour " << i + 1 << " ===============" << std::endl;

        p.Update();

        for (int j = 0; j < NB_RESSOURCE_TOUR; j++)
        {
            p.SpawnRessource();
        }

        p.Afficher();
    }

    return 0;
}
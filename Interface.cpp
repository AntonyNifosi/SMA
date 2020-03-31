#include "Plateau.hpp"
#include "Ressource.hpp"

#define NB_TOURS 100
#define NB_RESSOURCE_TOUR 10

#include <chrono>
#include <thread>

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
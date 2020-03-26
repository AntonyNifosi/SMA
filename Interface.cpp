#include "Plateau.hpp"
#include "Ressource.hpp"

#define NB_TOURS 50
#define NB_RESSOURCE_TOUR 4

#include <chrono>
#include <thread>

int main()
{
    Plateau p("Config/Config2.txt");
    std::cout << "=============== Tour 0 ===============" << std::endl;
    
    p.Afficher();
    
    for(int i = 0; i < NB_TOURS; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::cout << "=============== Tour " << i + 1 << " ===============" << std::endl;

        p.Update();

        for (int j = 0; j < NB_RESSOURCE_TOUR; j++)
        {
            int x, y;
            do
            {
                x = generateur() % 20;
                y = generateur() % 20;
            } while (p.recupCase(x, y) != nullptr);

            p.Ajouter(new Ressource(x, y), x, y);
        }

        p.Afficher();
    }

    return 0;
}
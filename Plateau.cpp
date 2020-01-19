#include "Plateau.hpp"

Plateau::Plateau()
{
}

Plateau::Plateau(std::string Nom)
{
}

Plateau::~Plateau()
{
    for(int i = 0; i < TAILLE_PLATEAU; i++)
    {
        for (int j = 0; i < TAILLE_PLATEAU; j++)
        {
            if(_plateau[i][j])
                delete _plateau[i][j];    
        }
    }
}

void Plateau::Afficher()
{
    for(int i = 0; i < TAILLE_PLATEAU; i++)
    {
        for (int j = 0; i < TAILLE_PLATEAU; j++)
        {
            if(_plateau[i][j])
                _plateau[i][j]->Afficher();
            else
                std::cout << "  ";            
        }
        std::cout << std::endl;
    }
}

void Plateau::Update()
{
    std::vector<Agent*>::iterator it;
    for(it = _agents.begin(); it != _agents.end(); it++)
    {
        (*it)->update();
    }
}
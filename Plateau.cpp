#include "Plateau.hpp"

Plateau::Plateau()
{
}

Plateau::Plateau(std::string Nom)
{
    std::ifstream fichier(Nom); 

    if(fichier)
    {
        char temp;
        for(int i = 0; i < TAILLE_PLATEAU; i++)
        {
            for(int j = 0; j < TAILLE_PLATEAU; j++)
            {
                fichier >> temp;
                switch (temp)
                {
                    case 'A':
                        _plateau[i][j] = new Agressif(i, j);
                        break;

                    case 'P':
                        _plateau[i][j] = new Passifish(i, j);
                        break;

                    case 'R':
                        _plateau[i][j] = new Ressource(i, j);
                        break;
                }
            }
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
    }
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

void Plateau::Ajouter(Entitee* e, int x, int y)
{

}

void Plateau::Delete(int x, int y)
{

}

Entitee* Plateau::recupCase(int x, int y)
{

}
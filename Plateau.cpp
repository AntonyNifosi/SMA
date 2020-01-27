#include "Plateau.hpp"
#include "Agressif.hpp"
#include "Passifish.hpp"
#include "Ressource.hpp"


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
                        {
                            Agressif* a = new Agressif(i, j);
                            _plateau[i][j] = a;
                            _agents.push_back(a);
                        }
                        break;

                    case 'P':
                        {
                            Passifish* p = new Passifish(i, j);
                            _plateau[i][j] = p;
                            _agents.push_back(p);
                        }
                        break;

                    case 'R':
                        _plateau[i][j] = new Ressource(i, j);
                        break;
                    default:
                        _plateau[i][j] = nullptr;
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
        for (int j = 0; j < TAILLE_PLATEAU; j++)
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
        for (int j = 0; j < TAILLE_PLATEAU; j++)
        {
            if(_plateau[i][j] != nullptr)
                _plateau[i][j]->Afficher();
            else
                std::cout << "  ";            
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void Plateau::Update()
{
    std::vector<Agent*>::iterator it;
    for(it = _agents.begin(); it != _agents.end(); it++)
    {
        (*it)->update(this);
    }
}

void Plateau::Ajouter(Entitee* e, int x, int y)
{
    _plateau[x][y] = e;
}

void Plateau::Ajouter(Agent* e, int x, int y)
{
    _plateau[x][y] = e;
    _agents.push_back(e);
}

void Plateau::Delete(int x, int y)
{

}

Entitee* Plateau::recupCase(int x, int y)
{
    return _plateau[x][y];
}

void Plateau::Deplacer(int x, int y, int dx, int dy)
{
    _plateau[x + dx][y + dy] = _plateau[x][y];
    _plateau[x][y] = nullptr;
}
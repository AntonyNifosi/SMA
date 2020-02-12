#include "Plateau.hpp"
#include "Agressif.hpp"
#include "Passifish.hpp"
#include "Ressource.hpp"
#include "Reader.hpp"
#include "Factory.hpp"


Plateau::Plateau()
{
}

Plateau::Plateau(std::string nom)
{
    Factory f;
    Reader *r = Reader::getInstance(nom);
    std::string config = r->readConfig();
    
    for (unsigned int i = 0; i < TAILLE_PLATEAU * TAILLE_PLATEAU; i++)
    {
        switch(config[i])
        { 
            case 'A':
            {
                Agressif* a = f.createAgressif();
                _plateau[(i/20)][i % 20] = a;
                a->setPos(Vector2(i / 20, i % 20));
                _agents.push_back(a);
            }
            break;

            case 'P':
            {
                Passifish* p = f.createPassifish();
                _plateau[(i/20)][i % 20] = p;
                p->setPos(Vector2(i / 20, i % 20));
                _agents.push_back(p);
            }
            break;

            case 'R':
            {
                Ressource* r = f.createRessource();
                _plateau[(i/20)][i % 20] = r;
                r->setPos(Vector2(i / 20, i % 20));
            }
            break;
            
            default:
                _plateau[(i/20)][i % 20] = nullptr;
                break;

        }            
    }
    std::cout << "Plateau INIT --> OK !" << std::endl;
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
                std::cout << " . ";            
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void Plateau::Update()
{
    std::cout << "Update du plateau taille vecteur agent : " << _agents.size() <<  std::endl;
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

void Plateau::Deplacer(Entitee* e, Vector2 v)
{
    int posx = e->getPosx();
    int posy = e->getPosy();
    
    Vector2 newPos(posx + v.getX(), posy + v.getY());

    e->setPos(newPos);

    _plateau[newPos.getX()][newPos.getY()] = _plateau[posx][posy];

    _plateau[posx][posy] = nullptr;
}
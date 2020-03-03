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
    
    Reader *r = Reader::getInstance(nom);
    std::string config = r->readConfig();
    
    for (unsigned int i = 0; i < TAILLE_PLATEAU; i++)
    {
        for (unsigned int j = 0; j < TAILLE_PLATEAU; j++)
        {
            switch(config[i * TAILLE_PLATEAU + j])
            { 
                case 'A':
                {
                    createAgent(AGRESSIF, Vector2(i, j));
                }
                break;

                case 'P':
                {
                    createAgent(PASSIFISH, Vector2(i, j));
                }
                break;

                case 'R':
                {
                    Ressource* r = f.createRessource();
                    _plateau[i][j] = r;
                    r->setPos(Vector2(i, j));
                }
                break;
                
                default:
                    _plateau[i][j] = nullptr;
                    break;
            }
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

void Plateau::createAgent(AgentType type, Vector2 position)
{
    switch (type)
    {
        case AGRESSIF:
        {
            Agressif* a = f.createAgressif();
            _plateau[position.getX()][position.getY()] = a;
            a->setPos(position);
            _agents.push_back(a);
        }
        break;

        case PASSIFISH:
        {
            Passifish* p = f.createPassifish();
            _plateau[position.getX()][position.getY()] = p;
            p->setPos(position);
            _agents.push_back(p);
        }  
        break;
    }
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

Vector2 Plateau::caseLibre(Entitee *e)
{
    Vector2 location (e->getPosx(), e->getPosy());

    for (int i = location.getY() - 1; i < location.getY() + 1; i++)
    {
        for (int j = location.getX() - 1; j < location.getX() + 1; j++)
        {
            if (_plateau[i][j] == nullptr)
            {
                return Vector2(i, j);
            }
        }
    }
    return Vector2(-1, -1);
}
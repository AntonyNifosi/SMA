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
            switch(config[i * (TAILLE_PLATEAU + 2) + j])
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
    delete(r);
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
    int nbAgressif = 0;
    int nbPassifish = 0;

    std::vector<Agent*>::iterator it;

    for(it = _agents.begin(); it != _agents.end(); it++)
    {
        if((*it)->JeSuis() == AGRESSIF)
        {
            nbAgressif++;
        }
        else
        {
            nbPassifish++;
        }
    }

    std::cout << "Nombre d'agressif : " << nbAgressif << std::endl;
    std::cout << "Nombre de Passifish : " << nbPassifish << std::endl;

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
    _agentsCur = _agents;

    std::vector<Agent*>::iterator it = _agentsCur.begin();
    while(it != _agentsCur.end())
    {
        if((*it)->isAvailable())
        {
            (*it)->update(this);

            if((*it)->mort())
            {
               Delete((*it));
            }
        }
        it++;
    }
    FreeDead();
}

void Plateau::FreeDead()
{
    std::vector<Agent*>::iterator it = _agents.begin();
    
    while(it !=  _agents.end())
    {
        if((*it) != nullptr && !(*it)->isAvailable())
        {
            Agent* a = (*it);
            _agents.erase(it);
            delete(a);
        }
        else
        {
            it++;
        }
    }
}

void Plateau::Ajouter(Entitee* e, int x, int y)
{
    _plateau[x][y] = e;
}

void Plateau::createAgent(EntiteeType type, Vector2 position)
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

        default:
        break;
    }
}

void Plateau::Ajouter(Agent* e, int x, int y)
{
    _plateau[x][y] = e;
    _agents.push_back(e);
}

void Plateau::Delete(Entitee *e)
{
    for (int i = 0; i < TAILLE_PLATEAU; i++)
    {
        for (int j = 0; j < TAILLE_PLATEAU; j++)
        {
            if (_plateau[i][j] == e)
            {
                _plateau[i][j] = nullptr;
            }
        }
    }
    if (e->JeSuis() != RESSOURCE)
    {
        e->setAvailable(false);
    }
    else if (e->JeSuis() == RESSOURCE)
    {
        delete(e);
    }
}

Entitee* Plateau::recupCase(int x, int y)
{
    return _plateau[x][y];
}

void Plateau::Deplacer(Entitee* e, Vector2 v)
{
    int posx = e->getX();
    int posy = e->getY();
    
    Vector2 newPos(posx + v.getX(), posy + v.getY());

    e->setPos(newPos);

    _plateau[newPos.getX()][newPos.getY()] = _plateau[posx][posy];

    _plateau[posx][posy] = nullptr;
}

Vector2 Plateau::caseLibre(Entitee *e)
{
    Vector2 location (e->getVector());

    for (int i = location.getX() - 1; i <= location.getX() + 1; i++)
    {
        int distX = abs(location.getX() - i);
        for (int j = location.getY() - 1 + distX; j <= location.getY() + 1 - distX; j += 2)
        {
            if (i >= 0 && i < TAILLE_PLATEAU && j >= 0 && j < TAILLE_PLATEAU && _plateau[i][j] == nullptr)
            {
                return Vector2(i, j);
            }
        }
    }
    return Vector2(-1, -1);
}

Vector2 Plateau::PathFinding(Vector2 depart, Vector2 arrive)
{
    std::array<std::array<int, TAILLE_PLATEAU>, TAILLE_PLATEAU> _matrice;
    std::array<std::array<int, TAILLE_PLATEAU>, TAILLE_PLATEAU> _utilise;

    for (unsigned int i = 0; i < TAILLE_PLATEAU; i++)
    {
        for (unsigned int j = 0; j < TAILLE_PLATEAU; j++)
        {
            _matrice[i][j] = 9999;
            _utilise[i][j] = 0;
        }
    }  

    _matrice[depart.getX()][depart.getY()] = 0;

    int ite = 0;

    while(_matrice[arrive.getX()][arrive.getY()] == 9999)
    {
        Vector2 location(0, 0);
        int dist = 9999;
        for (unsigned int i = 0; i < TAILLE_PLATEAU; i++)
        {
            for (unsigned int j = 0; j < TAILLE_PLATEAU; j++)
            {
                if(_matrice[i][j] < dist && !_utilise[i][j])
                {
                    dist = _matrice[i][j];
                    location.setX(i);
                    location.setY(j);
                }
            }
        }

        for (int i = location.getX() - 1; i <= location.getX() + 1; i++)
        {
            int distX = abs(location.getX() - i);
            for (int j = location.getY() - 1 + distX; j <= location.getY() + 1 - distX; j += 2)
            {
                if(j >= 0 && j < TAILLE_PLATEAU && i >= 0 && i < TAILLE_PLATEAU)
                {
                    if(_matrice[i][j] > _matrice[location.getX()][location.getY()] && (_plateau[i][j] == nullptr || (i == arrive.getX() && j == arrive.getY())))
                    {
                        _matrice[i][j] = _matrice[location.getX()][location.getY()] + 1;
                    }
                }
            }
        }

        _utilise[location.getX()][location.getY()] = 1;

        ite++;
        if(ite > 100)
        {
            return Vector2(0, 0);
        }
    }

    return Recup_Chemin(depart, arrive, _matrice);
}

Vector2 Plateau::Recup_Chemin(
    Vector2 depart, 
    Vector2 arrive, 
    std::array<std::array<int, TAILLE_PLATEAU>, TAILLE_PLATEAU> _matrice)
{
    Vector2 act(arrive.getX(), arrive.getY());
    Vector2 depl(0, 0);

    while(act != depart)
    {
        for (int i = act.getX() - 1; i <= act.getX() + 1; i++)
        {
            int distX = abs(act.getX() - i);
            for (int j = act.getY() - 1 + distX; j <= act.getY() + 1 - distX; j += 2)
            {
                if(j >= 0 && j < TAILLE_PLATEAU && i >= 0 && i < TAILLE_PLATEAU)
                {
                    if(_matrice[i][j] == _matrice[act.getX()][act.getY()] - 1)
                    {
                        depl.setX(act.getX() - i);
                        depl.setY(act.getY() - j);

                        act.setX(i);
                        act.setY(j);
                    }
                }
            }
        }
    }

    return depl;
}

void Plateau::SpawnRessource()
{   
    bool libre = false;
    for(int i = 0; i < TAILLE_PLATEAU; i++)
    {
        for(int j = 0; j < TAILLE_PLATEAU; j++)
        {
            if(_plateau[i][j] == nullptr)
            {
                libre = true;
            }
        }
    }
    if(libre)
    {
        int x, y;
        do
        {
            x = generateur() % 20;
            y = generateur() % 20;
        } while (recupCase(x, y) != nullptr);

        Ajouter(new Ressource(x, y), x, y);
    }
}
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

    _agentsCur = _agents;

    std::vector<Agent*>::iterator it = _agentsCur.begin();
    while(it != _agentsCur.end())
    {
        (*it)->update(this);
                
        if((*it)->mort())
        {
            Delete((*it));
        }
        it++;
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
    if (e->JeSuis() != "Ressource")
    {
        if (e != nullptr)
        {
            for(unsigned int i = 0; i < _agents.size(); i++)
            {
                if (_agents[i] == e)
                {
                    _agents.erase(_agents.begin() + i);
                }
            }

            for(unsigned int i = 0; i < _agentsCur.size(); i++)
            {
                if (_agentsCur[i] == e)
                {
                    _agentsCur.erase(_agentsCur.begin() + i);
                }
            }
        } 
    }
    delete(e);
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
                if(j >= 0 && j <= TAILLE_PLATEAU && i >= 0 && i <= TAILLE_PLATEAU)
                {
                    if(_matrice[i][j] > _matrice[location.getX()][location.getY()])
                    {
                        _matrice[i][j] = _matrice[location.getX()][location.getY()] + 1;
                    }
                }
            }
        }

        _utilise[location.getX()][location.getY()] = 1;
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
                if(j >= 0 && j <= TAILLE_PLATEAU && i >= 0 && i <= TAILLE_PLATEAU)
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
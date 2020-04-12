/**
 * @file Plateau.cpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Implémentation des fonctions relatives à la classe Plateau
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2019
 */

#include "Plateau.hpp"
#include "Reader.hpp"
#include "Factory.hpp"

/**
 * @brief Constructeur de la classe Plateau.
 *        Génération du _plateau aléatoirement
 */
Plateau::Plateau()
{
    for (unsigned int i = 0; i < TAILLE_PLATEAU; i++)
    {
        for (unsigned int j = 0; j < TAILLE_PLATEAU; j++)
        {
            float a = generateur() % 100;

            if(a < 3)
            {
                createAgent(AGRESSIF, Vector2(i, j));
            }
            else if (a < 6)
            {
                createAgent(PASSIFISH, Vector2(i, j));
            }
            else if (a < 12)
            {
                Ressource* r = f.createRessource();
                _plateau[i][j] = r;
                r->setPos(Vector2(i, j));
            }
            else
            {
                _plateau[i][j] = nullptr;
            }
            
        }
    }
}

/**
 * @brief Constructeur de la classe Plateau à partir d'un fichier 
 * 
 * @param nom du fichier à utiliser
 */

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

/**
 * @brief Destructeur de la class Plateau
 */
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

/**
 * @brief Affiche le contenu actuel du Plateau
 */
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

/**
 * @brief Réalise une mise à de tous les Agent sur le _plateau
 */
void Plateau::Update()
{
    std::shuffle( _agentsCur.begin(), _agentsCur.end(), generateur);

    _agentsCur = _agents;

    std::vector<Agent*>::iterator it = _agentsCur.begin();
    while(it != _agentsCur.end())
    {
        if(!(*it)->isMort())
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

/**
 * @brief Libère les Agent mort lors de la procédure Update 
 */
void Plateau::FreeDead()
{
    std::vector<Agent*>::iterator it = _agents.begin();
    
    while(it !=  _agents.end())
    {
        if((*it) != nullptr && (*it)->isMort())
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

/**
 * @brief Ajoute une Entitee sur le _plateau
 * 
 * @param e Entitee à ajouter
 * @param x position x de l'Entitee
 * @param y position y de l'Entitee
 */
void Plateau::Ajouter(Entitee* e, int x, int y)
{
    _plateau[x][y] = e;
}

/**
 * @brief Crée un Agent selon le type passé en paramètres
 * 
 * @param type type de l'Agent à créer
 * @param position position à laquel créer l'Agent
 */
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

/**
 * @brief Ajoute un Agent sur le _plateau
 * 
 * @param e Agent à ajouter
 * @param x Position x de l'Agent
 * @param y Position y de l'Agent
 */
void Plateau::Ajouter(Agent* e, int x, int y)
{
    _plateau[x][y] = e;
    _agents.push_back(e);
}

/**
 * @brief Supprime une Entitee du Plateau et la déclare comme morte pour ne pas la traiter dans le Vecteur _agents
 * 
 * @param e Entitee à supprimer
 */
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
        e->setMort(true);
    }
    else if (e->JeSuis() == RESSOURCE)
    {
        delete(e);
    }
}

/**
 * @brief Récupère le contenu d'une case du _plateau à une position choisie
 * 
 * @param x
 * @param y 
 * @return Entitee* Pointeur sur le contenu de la case 
 */
Entitee* Plateau::recupCase(int x, int y)
{
    return _plateau[x][y];
}

/**
 * @brief Déplace une Entitee sur le Plateau 
 * 
 * @param e Entitee à déplacer
 * @param v Déplacement à éffectuer
 */
void Plateau::Deplacer(Entitee* e, Vector2 v)
{
    int posx = e->getX();
    int posy = e->getY();
    
    Vector2 newPos(posx + v.getX(), posy + v.getY());

    e->setPos(newPos);

    _plateau[newPos.getX()][newPos.getY()] = _plateau[posx][posy];

    _plateau[posx][posy] = nullptr;
}

/**
 * @brief Récupère une case libre autour d'une Entitee
 * 
 * @param e Entitee autour de laquelle faire la recherche
 * @return Vector2 Une case libre autour, (-1, -1) si aucune case n'est trouvée
 */
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

/**
 * @brief Calcul le déplacement à réaliser pour aller d'une position de depart à une position d'arrivée en fonction de l'êtat actuel du plateau
 * 
 * @param depart Vector2 contenant la position de départ
 * @param arrive Vector2 contenant la position d'arrivée
 * @return Vector2 Déplacement à éffectuer
 * @callergraph
 */
Vector2 Plateau::PathFinding(Vector2 depart, Vector2 arrive)
{
    std::array<std::array<int, TAILLE_PLATEAU>, TAILLE_PLATEAU> _matrice;
    std::array<std::array<int, TAILLE_PLATEAU>, TAILLE_PLATEAU> _utilise;

    // Initialisation des variables
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

    // Création des chemins
    while(_matrice[arrive.getX()][arrive.getY()] == 9999)
    {
        Vector2 location(0, 0);
        int dist = 9999;

        //Récupération de la case avec la plus petite distance du point de depart
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

        //Update de toutes les cases adjacentes
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

        //Si aucun chemin n'est trouvable on met une sécurité
        ite++;
        if(ite > 100)
        {
            return Vector2(0, 0);
        }
    }

    return Recup_Chemin(depart, arrive, _matrice);
}

/**
 * @brief Récupération du déplacement à réaliser grace à la _matrice contenant les chemins possible
 * 
 * @param depart Vector2 contenant la position de départ
 * @param arrive Vector2 contenant la position de arrivée
 * @param _matrice Contient au moins un chemin relliant le position de dépat et celle d'arrivée
 * @return Vector2 Déplacement à effectuer
 */
Vector2 Plateau::Recup_Chemin(
    Vector2 depart, 
    Vector2 arrive, 
    std::array<std::array<int, TAILLE_PLATEAU>, TAILLE_PLATEAU> _matrice)
{
    //On démarre de la fin
    Vector2 act(arrive.getX(), arrive.getY());
    Vector2 depl(0, 0);

    //Tant qu'on est pas remonté au départ
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

/**
 * @brief Crée une ressource sur le _plateau sur une case libre
 * 
 */
void Plateau::SpawnRessource()
{   
    bool libre = false;
    //On regarde si le _plateau possède une case libre
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
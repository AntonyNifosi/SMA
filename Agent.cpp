/**
 * @file Agent.cpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Implémentation des fonctions relatives à la classe Entitee
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */


#include "Agent.hpp"
#include "Plateau.hpp"

/**
 * @brief Constructeur de la classe Agent
 * 
 * @param x position x de l'Agent
 * @param y position y de l'Agent
 * @param vision champ de vision de l'Agent
 */
Agent::Agent(int x, int y, int vision) : 
Entitee(x, y), _age(0), _time_no_eat(0), _vision(vision)
{}

/**
 * @brief Destructeur de la classe Agent
 * 
 */
Agent::~Agent()
{}

/**
 * @brief Update de l'Agent
 * @details L'agent va chercher dans son champ de vision une cible. 
 * Si une cible est trouvé l'Agent va alors essayer de se rapprocher de la cible.
 * Sinon il va se déplacer sur case alétoire autour de lui si une case est libre.
 * 
 * @param p Le Plateau sur lequel évolue l'Agent
 */
void Agent::update(Plateau* p)
{
    //On récupère les Cible potentiel autour de l'agent
    std::vector<Cible_t> cibles = EnVue(p);

    _age++;
    _time_no_eat++;

    //L'agent selectionne sa cible
    Cible_t c = Selection(cibles);

    //Si une cible est séléctionné
    if(c.distance != 9999)
    {
        Vector2 depl = p->PathFinding(_pos, c.cible->getVector());
        
        move(depl, p);

        if(c.distance == 1)
        {  
            Traitement(p, c); 
        }
    }
    else
    {  
        int new_x = 0, new_y = 0;

        bool case_vide = false;

        //On regarde si une case autour de l'agent est vide
        for (int i = _pos.getX() - 1; i <= _pos.getX() + 1; i++)
        {
            int distX = abs(_pos.getX() - i);
            for (int j = _pos.getY() - 1 + distX; j <= _pos.getY() + 1 - distX; j += 2)
            {
                if(i >= 0 && i < TAILLE_PLATEAU && j >= 0 && j < TAILLE_PLATEAU && p->recupCase(i, j) == nullptr)
                {
                    case_vide = true;
                }
            }
        }

        if(case_vide)
        {
            //On génère un déplacement aléatoire
            do
            {
                if(generateur() % 2)
                {
                    new_x = (generateur() % 2) * 2 - 1;
                    new_y = 0;
                }
                else
                {
                    new_x = 0;
                    new_y = (generateur() % 2) * 2 - 1;
                }
            }while (
                _pos.getX() + new_x < 0 || _pos.getX() + new_x >= TAILLE_PLATEAU ||
                _pos.getY() + new_y < 0 || _pos.getY() + new_y >= TAILLE_PLATEAU ||
                p->recupCase(_pos.getX() + new_x, _pos.getY() + new_y) != nullptr);
        }
        
        move(Vector2(new_x, new_y), p);
    }
}

/**
 * @brief Déplace un Agent
 * 
 * @param dep Déplacement à réaliser
 * @param p Plateau sur lequel évolue l'Agent
 */
void Agent::move(Vector2 dep, Plateau* p)
{
    int newPosX = _pos.getX() + dep.getX();
    int newPosY = _pos.getY() + dep.getY();

    if(newPosX >= 0 && newPosX < TAILLE_PLATEAU && newPosY >= 0 && newPosY < TAILLE_PLATEAU)
    {
        if (p->recupCase(newPosX, newPosY) == nullptr)
        {
            p->Deplacer(this, dep);
        }
    }
}

/**
 * @brief Récupère les cibles potentiels présentes dans le champ de vision de l'Agent
 * 
 * @param p Plateau sur lequel évolue l'Agent
 * @return std::vector<Cible_t> Vecteur contenant toutes les cibles potentiel
 */
std::vector<Cible_t> Agent::EnVue(Plateau* p)
{
    std::vector<Cible_t> Cibles;

    for(int i = _pos.getX() - _vision; i <= _pos.getX() + _vision; i++)
    {
        if(i >= 0 && i < TAILLE_PLATEAU)
        {
            int distI = abs(_pos.getX() - i);
            for(int j = _pos.getY() - _vision + distI; j <= _pos.getY() + _vision - distI; j++)
            {
                if( j >= 0 && j < TAILLE_PLATEAU && !(j == _pos.getY() && i == _pos.getX()))
                {
                    Entitee* e = p->recupCase(i, j); 
                    if(e != nullptr)
                    {
                        Cible_t c;
                        c.cible = e;
                        c.distance = abs(_pos.getX() - i) + abs(_pos.getY() - j);
                        Cibles.push_back(c);
                    }
                }
            }
        }
    }

    return Cibles;
}

/**
 * @brief Affiche la liste des cibles disponibles
 * 
 * @param cibles Vecteur contenant les listes
 */
void Agent::afficherCible(std::vector<Cible_t> cibles)
{
    std::vector<Cible_t>::iterator it;
    for(it = cibles.begin(); it != cibles.end(); it++ )
    {
        std::cout << (*it).cible->JeSuis() << " distance : " << (*it).distance << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Crée un nouvel Agent adjacent à celui actuel
 * 
 * @param p Plateau sur lequel évolue l'Agent
 */
void Agent::seReproduire(Plateau *p)
{
    Vector2 location = p->caseLibre(this);
    if (location.isValidPosition())
    {
        if (JeSuis() == AGRESSIF)
            p->createAgent(AGRESSIF, location);
        else
            p->createAgent(PASSIFISH, location);
    }
}

/**
 * @brief L'Agent mange une Entitee
 * 
 * @param p Plateau sur lequel évolue l'Agent
 * @param e Entitee à manger
 */
void Agent::manger(Plateau *p, Entitee *e)
{
    _time_no_eat = 0;
    p->Delete(e);
}
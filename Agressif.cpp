#include "Agressif.hpp"
#include "Plateau.hpp"

Agressif::Agressif() : Agent(0, 0, 4)
{}

Agressif::Agressif(int x, int y):
Agent(x, y, 4)
{}

void Agressif::update(Plateau *p)
{
    std::vector<Cible_t> cibles = EnVue(p);

    _age++;
    _time_no_eat++;

    Cible_t c = Selection(cibles);


    if(c.distance != 9999)
    {
        std::cout << JeSuis() << " en " << _pos.getX() << " " << _pos.getY() << " a selectionné : " << c.cible->JeSuis() << std::endl;
        std::cout << "Distance : " << c.distance << std::endl ;
        std::cout << "Position : " << c.cible->getX() << " " << c.cible->getY() << std::endl;

        Vector2 depl = p->PathFinding(_pos, c.cible->getVector());

        std::cout << "Deplacement à effectué : " << depl.getX() << " " << depl.getY() << std::endl;

        move(depl, p);

        if(getVector().distance(c.cible->getVector()) == 1)
        {
            
        }
    }
    else
    {   
        std::cout << "Agressif en " << _pos.getX() << " " << _pos.getY() << " a selectionné : rien" << std::endl;
        
        int new_x = 0, new_y = 0;

        if(!(p->recupCase(_pos.getX() + 1, _pos.getY()) != nullptr && 
             p->recupCase(_pos.getX() - 1, _pos.getY()) != nullptr &&
             p->recupCase(_pos.getX(), _pos.getY() + 1) != nullptr &&
             p->recupCase(_pos.getX(), _pos.getY() - 1) != nullptr))
        {
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
                
            }while (p->recupCase(_pos.getX() + new_x, _pos.getY() + new_y) != nullptr);
        }
        move(Vector2(new_x, new_y), p);
    }
}

Cible_t Agressif::Selection(std::vector<Cible_t> cibles)
{
    std::vector<Cible_t>::iterator it;

    Cible_t c;
    c.distance = 9999;
    
    for(it = cibles.begin(); it != cibles.end(); it++ )
    {
        if((*it).cible->JeSuis() != "Agressif" || Affame())
        {
            if(c.distance > (*it).distance)
            {
                c = (*it);
            }
        }
    }

    return c;
}

void Agressif::Afficher()
{
    std::cout << " A ";
}

bool Agressif::Affame()
{
    return _time_no_eat > 5;
}

std::string Agressif::JeSuis()
{
    return "Agressif";
}

bool Agressif::mort()
{
    return _time_no_eat > 10;
}
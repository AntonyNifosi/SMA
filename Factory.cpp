#include "Factory.hpp"

Factory::Factory()
{

}

Passifish* Factory::createPassifish()
{
    Passifish* p = new Passifish();
    return p;
}   

Agressif* Factory::createAgressif()
{
    Agressif* a = new Agressif();
    return a;
}

Ressource* Factory::createRessource()
{
    Ressource* r = new Ressource();
    return r;
}
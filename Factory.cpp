#include "Factory.hpp"

Factory::Factory()
{

}

Passifish* Factory::createPassifish()
{
    Passifish* p = new Passifish();
    std::cout << "Agent : " << p << std::endl; 
    return p;
}   

Agressif* Factory::createAgressif()
{
    Agressif* a = new Agressif();
    std::cout << "Agent : " << a << std::endl; 
    return a;
}

Ressource* Factory::createRessource()
{
    Ressource* r = new Ressource();
    std::cout << "Agent : " << r << std::endl; 
    return r;
}
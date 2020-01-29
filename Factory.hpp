#ifndef FACTORY_HPP
#define FACTORY_HPP


#include <array>
#include "Reader.hpp"
#include "Passifish.hpp"
#include "Agressif.hpp"
#include "Ressource.hpp"


class Factory
{
    public :
        Factory();
        Passifish* createPassifish();
        Agressif* createAgressif();
        Ressource* createRessource();
};

#endif
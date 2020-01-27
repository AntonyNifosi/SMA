#include <array>
#include "Reader.hpp"
#include "Passifish.hpp"
#include "Agressif.hpp"
#include "Ressource.hpp"


class Factory
{
    public :
        Factory();
        static std::array<std::array<Entitee*, 20>, 20> createAgents();
};
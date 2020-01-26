#include <array>
#include "Agent.hpp"
#include "Passifish.hpp"
#include "Agressif.hpp"
#include "Ressource.hpp"
#include "Reader.hpp"

class Factory
{
    public :
        Factory();
        static std::array<std::array<Entitee*, 20>, 20> createAgents();
};
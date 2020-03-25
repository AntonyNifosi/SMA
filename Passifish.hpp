#ifndef PASSIFISH_HPP
#define PASSIFISH_HPP

#include "Agent.hpp"

class Passifish : public Agent
{
    public:
        Passifish();
        Passifish(int x, int y);
        // ~Passifish();
		bool Mort();
        void Afficher();
        std::string JeSuis();
		Cible_t Selection(std::vector<Cible_t> cibles);
        bool Tuable(Cible_t c, std::vector<Cible_t> cibles);
        void Traitement(Cible_t c);
};

#endif
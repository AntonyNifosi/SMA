#ifndef PASSIFISH_HPP
#define PASSIFISH_HPP

#include "Agent.hpp"

class Passifish : public Agent
{
    public:
        Passifish();
        Passifish(int x, int y);
        // ~Passifish();
		void update(Plateau* p);
		bool Mort();
        void Afficher();
        std::string JeSuis();
};

#endif
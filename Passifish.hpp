#ifndef PASSIFISH_HPP
#define PASSIFISH_HPP

#include "Agent.hpp"

class Passifish : public Agent
{
    public:
        Passifish(int x, int y);
        ~Passifish();
		void update();
		void move();
		bool dead();
        void Afficher();
        std::string JeSuis();
};

#endif
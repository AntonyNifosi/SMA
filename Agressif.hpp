#ifndef AGRESSIF_HPP
#define AGRESSIF_HPP

#include "Agent.hpp"

class Agressif : public Agent
{
	private :

	public :
		Agressif(int x, int y);
		// ~Agressif();
		// void update();
		// void move();
		// bool dead();
        void Afficher();
        std::string JeSuis();
};

#endif
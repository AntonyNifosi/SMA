#ifndef AGRESSIF_HPP
#define AGRESSIF_HPP

#include "Agent.hpp"

class Agressif : public Agent
{
	private :

	public :
		Agressif();
		Agressif(int x, int y);
		// ~Agressif();
		void update(Plateau* p);
		// void move();
		// bool dead();
        void Afficher();
        std::string JeSuis();
};

#endif
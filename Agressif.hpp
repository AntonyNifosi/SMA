#ifndef AGRESSIF_HPP
#define AGRESSIF_HPP

#include "Agent.hpp"

class Agressif : public Agent
{
	private :

	public :
		Agressif(int i, int j);
		~Agressif();
		void update();
		void move();
		bool dead();
        void Afficher();
        std::string JeSuis();
};

#endif
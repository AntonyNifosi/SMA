#ifndef AGRESSIF_HPP
#define AGRESSIF_HPP

#include "Entitee.hpp"

class Agressif : public Agent
{
	private :

	public :
		Agressif();
		~Agressif();
		void update();
		void move();
		bool dead();
};

#endif
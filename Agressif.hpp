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
		bool mort();
        void Afficher();
        std::string JeSuis();
		Cible_t Selection(std::vector<Cible_t> cibles);
		bool Affame();
};

#endif
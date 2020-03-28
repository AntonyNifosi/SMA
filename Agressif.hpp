#ifndef AGRESSIF_HPP
#define AGRESSIF_HPP

#include "Agent.hpp"

class Agressif : public Agent
{
	private :
		int reprod = 0;
	public :
		Agressif();
		Agressif(int x, int y);
		~Agressif();
		bool mort();
        void Afficher();
        std::string JeSuis();
		Cible_t Selection(std::vector<Cible_t> cibles);
		bool Affame();
        void Traitement(Plateau *p, Cible_t c);
};

#endif
#ifndef AGENT_HPP
#define AGENT_HPP

#include <iostream>

#include "Vector2.hpp"
#include "Entitee.hpp"

class Plateau;

typedef struct Cible
{
	Entitee* cible;
	int distance;
}Cible_t;

class Agent : public Entitee
{
	protected :
		int _age;
		int _time_no_eat;
		int _vision;

	public :
		Agent(int x, int y, int vision);
		~Agent();
		virtual void update(Plateau* p);
		void move(Vector2 dir, Plateau* p);
		std::vector<Cible_t> EnVue(Plateau* p);
		void afficherCible(std::vector<Cible_t> cibles);
		void seReproduire(Plateau *p);
		void manger(Plateau *p, Entitee *e);
		virtual bool mort() = 0;
		virtual Cible_t Selection(std::vector<Cible_t> cibles) = 0;
		virtual void Traitement(Plateau *p, Cible_t c) = 0;
};

#endif
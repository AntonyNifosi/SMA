#ifndef AGENT_HPP
#define AGENT_HPP

#include <cmath>
#include <iostream>
#include "Plateau.hpp"
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
		Vector2 direction;

	public :
		Agent(int x, int y, int vision);
		~Agent();
		virtual void update(Plateau* p);
		void move(Vector2 dir, Plateau* p);
		bool dead();
		bool isAffame();
		std::vector<Cible_t> EnVue(Plateau* p);
		void afficherCible(std::vector<Cible_t> cibles);
};

#endif
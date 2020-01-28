#ifndef AGENT_HPP
#define AGENT_HPP


#include <iostream>
#include "Vector2.hpp"
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
		bool _affame;
		Vector2 direction;

	public :
		Agent(int x, int y);
		~Agent();
		void update(Plateau* p);
		void move(Vector2 dir);
		bool dead();
		std::vector<Cible_t> EnVue(Plateau* p);
};

#endif
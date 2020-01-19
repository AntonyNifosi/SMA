#ifndef AGENT_HPP
#define AGENT_HPP

#include "Entitee.hpp"

#include <iostream>

class Agent : public Entitee
{
	protected :
		int _age;
		int _time_no_eat;
		bool _affame;

	public :
		Agent(int x, int y);
		~Agent();
		void update();
		void move();
		bool dead();
};

#endif
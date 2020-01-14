#include <iostream>

class Agent
{
	private :
		static int const life_time;
		static int const range;
		int age;
		int time_no_eat;
		bool starved;
		

	public :
		Agent();
		~Agent();
		void update();
		void move();
		bool dead();
};



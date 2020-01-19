#ifndef PASSIFISH_HPP
#define PASSIFISH_HPP

class Passifish : public Agent
{
    public:
        Passifish();
        ~Passifish();
		void update();
		void move();
		bool dead();
};

#endif
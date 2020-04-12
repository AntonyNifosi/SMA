/**
 * @file Agent.hpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Interface de la classe Agent
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#ifndef AGENT_HPP
#define AGENT_HPP

#include "Entitee.hpp"

class Plateau;

/**
 * @brief Structure contenant une cible potentiel pour l'Agent
 * 
 */
typedef struct Cible
{
	///Cible potentiel 
	Entitee* cible;
	///Distance de la cible
	int distance;
}Cible_t;

/**
 * @brief classe mère des différentes Agent
 * 
 */
class Agent : public Entitee
{
	protected :
		///Age de l'Agent
		int _age;
		///Temps depuis lequel l'Agent n'a pas mangé
		int _time_no_eat;
		///Champ de vision de l'Agent
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

		/**
		 * @brief Mort de l'Agent
		 * 
		 * @return true l'Agent est mort
		 * @return false sinon
		 */
		virtual bool mort() = 0;
		
		/**
		 * @brief L'Agent séléctionne sa cible parmi les Entitee dans son champ de vision
		 * 
		 * @param cibles Vecteur contenant les Entitee visibles par l'Agent
		 * @return Cible_t la Cible séléctionnée
		 */
		virtual Cible_t Selection(std::vector<Cible_t> cibles) = 0;

		/**
		 * @brief Traitement de la Cible lorsque l'Agent est à coté de sa Cible en fonction du type de la Cible et de l'Agent
		 * 
		 * @param p Plateau sur lequel évolue l'Agent
		 * @param c Cible à traiter
		 */
		virtual void Traitement(Plateau *p, Cible_t c) = 0;
};

#endif
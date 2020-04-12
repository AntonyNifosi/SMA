/**
 * @file Agressif.hpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Interface de la classe Agressif
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#ifndef AGRESSIF_HPP
#define AGRESSIF_HPP

#include "Agent.hpp"

/**
 * @brief Agent de type Agressif il cherche les cible les plus proches de lui.
 * 		  Après un certain temps sans manger il peuvent devenir cannibale
 * 
 */
class Agressif : public Agent
{
	private :
		///Niveau de reproduction de l'Agressif lorsque le niveau arrive à 1 l'Agressif se reproduit
		int reprod = 0;
	public :
		Agressif();
		Agressif(int x, int y);
		~Agressif();
		bool mort();
        void Afficher();
        EntiteeType JeSuis();
		Cible_t Selection(std::vector<Cible_t> cibles);
		bool Affame();
        void Traitement(Plateau *p, Cible_t c);
};

#endif
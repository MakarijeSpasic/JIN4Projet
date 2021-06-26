#pragma once
#include "SFML/Graphics.hpp"
#include <Level.h>

//variable globale d�finissant le nombre d'�l�ments de menu � afficher, permet de partager la fen�tre
//pour faire un affichage propre et de suivre les �l�ments s�lectionn�s

class LevelBuilder
{
public:
	virtual ~LevelBuilder();
	//R�initilialise le builder
	virtual void reset() = 0;

	//Les fonctions � impl�menter par les diff�rents builders:
	virtual void setMap() = 0;
	virtual void setPlayerPosition() = 0;
	virtual void setMonsters(b2World* world) = 0;
};

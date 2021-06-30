#pragma once
#include "SFML/Graphics.hpp"
#include <Level.h>

//Classe abstraite qui permet de structurer les builder de niveaux, les classes qui en h�ritent sont les classes
//� appeler lorsqu'on voudra faire un niveau du "style" de la classe � appeler.

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

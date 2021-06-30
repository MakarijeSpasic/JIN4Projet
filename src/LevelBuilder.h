#pragma once
#include "SFML/Graphics.hpp"
#include <Level.h>

//Classe abstraite qui permet de structurer les builder de niveaux, les classes qui en héritent sont les classes
//à appeler lorsqu'on voudra faire un niveau du "style" de la classe à appeler.

class LevelBuilder
{
public:
	virtual ~LevelBuilder();
	//Réinitilialise le builder
	virtual void reset() = 0;

	//Les fonctions à implémenter par les différents builders:
	virtual void setMap() = 0;
	virtual void setPlayerPosition() = 0;
	virtual void setMonsters(b2World* world) = 0;
};

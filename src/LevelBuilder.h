#pragma once
#include "SFML/Graphics.hpp"
#include <Level.h>

//variable globale définissant le nombre d'éléments de menu à afficher, permet de partager la fenêtre
//pour faire un affichage propre et de suivre les éléments sélectionnés

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

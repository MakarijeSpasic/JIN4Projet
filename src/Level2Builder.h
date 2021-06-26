#pragma once
#include "SFML/Graphics.hpp"
#include <LevelBuilder.h>

//variable globale définissant le nombre d'éléments de menu à afficher, permet de partager la fenêtre
//pour faire un affichage propre et de suivre les éléments sélectionnés

class Level2Builder : public LevelBuilder
{
public:
	Level2Builder();
	~Level2Builder();

	//Réinitilialise le builder
	virtual void reset() override;

	//Les fonctions à implémenter par les différents builders:
	virtual void setMap() override;	   
	virtual void setPlayerPosition() override;
	virtual void setMonsters(b2World* world) override;

	Level* getLevel();

private: 
	Level* level;

};

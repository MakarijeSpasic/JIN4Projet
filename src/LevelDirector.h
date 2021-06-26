#pragma once
#include <LevelBuilder.h>

//variable globale définissant le nombre d'éléments de menu à afficher, permet de partager la fenêtre
//pour faire un affichage propre et de suivre les éléments sélectionnés

class LevelDirector
{
public:
	void setBuilder(LevelBuilder* givenBuilder) {
		this->builder = givenBuilder;
	}

	void BuildLevel(b2World* world) {
		builder->setMap();
		builder->setPlayerPosition();
		builder->setMonsters(world);

	}



private:
	LevelBuilder* builder;
};

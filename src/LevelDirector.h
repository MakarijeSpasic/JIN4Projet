#pragma once
#include <LevelBuilder.h>

//variable globale définissant le nombre d'éléments de menu à afficher, permet de partager la fenêtre
//pour faire un affichage propre et de suivre les éléments sélectionnés

class LevelDirector
{
public:
	void setBuilder(LevelBuilder* givenBuilder);

	void BuildLevel(b2World* world);



private:
	LevelBuilder* builder;
};

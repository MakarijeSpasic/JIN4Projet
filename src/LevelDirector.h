#pragma once
#include <LevelBuilder.h>

//variable globale d�finissant le nombre d'�l�ments de menu � afficher, permet de partager la fen�tre
//pour faire un affichage propre et de suivre les �l�ments s�lectionn�s

class LevelDirector
{
public:
	void setBuilder(LevelBuilder* givenBuilder);

	void BuildLevel(b2World* world);



private:
	LevelBuilder* builder;
};

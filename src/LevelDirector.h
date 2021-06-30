#pragma once
#include <LevelBuilder.h>

//variable globale d�finissant le nombre d'�l�ments de menu � afficher, permet de partager la fen�tre
//pour faire un affichage propre et de suivre les �l�ments s�lectionn�s

class LevelDirector
{
public:
	//Permet de d�finir le builder de niveau qu'il faut.
	void setBuilder(LevelBuilder* givenBuilder);

	//La m�thode contenant l'algorithme de construction du niveau
	void BuildLevel(b2World* world);



private:
	LevelBuilder* builder;
};

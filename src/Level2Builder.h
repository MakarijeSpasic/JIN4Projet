#pragma once
#include "SFML/Graphics.hpp"
#include <LevelBuilder.h>

//variable globale d�finissant le nombre d'�l�ments de menu � afficher, permet de partager la fen�tre
//pour faire un affichage propre et de suivre les �l�ments s�lectionn�s

class Level2Builder : public LevelBuilder
{
public:
	Level2Builder();
	~Level2Builder();

	//R�initilialise le builder
	virtual void reset() override;

	//Les fonctions � impl�menter par les diff�rents builders:
	virtual void setMap() override;	   
	virtual void setPlayerPosition() override;
	virtual void setMonsters(b2World* world) override;

	Level* getLevel();

private: 
	Level* level;

};

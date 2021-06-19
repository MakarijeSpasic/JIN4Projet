#pragma once
#include "SFML/Graphics.hpp"
#include "Menu.h"

//variable globale d�finissant le nombre d'�l�ments de menu � afficher, permet de partager la fen�tre
//pour faire un affichage propre et de suivre les �l�ments s�lectionn�s
#define MAX_NUMBER_OF_ITEMS 2

class EcranAcceuil: public Menu
{
public:
	EcranAcceuil(float width, float height);

	//"Dessine" le menu sur la fen�tre
	void draw(sf::RenderWindow* window) override;

	//G�rent les s�lections de �l�ments de menus via les touches directionnelles "haut" et "bas"
	void MoveUp() override;
	void MoveDown() override;

	bool ExecuteElement(int selectedItem, sf::RenderWindow* window, PersonnageJoueur* PJ) override;

private:
	//Stocke les textes � afficher, ils sont modifi�s pour avoir un suivi graphique de l'�l�ment de menu
	//s�l�ctionn�
	sf::Text text[MAX_NUMBER_OF_ITEMS];
};

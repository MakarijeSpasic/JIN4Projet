#pragma once
#include "SFML/Graphics.hpp"

//variable globale définissant le nombre d'éléments de menu à afficher, permet de partager la fenêtre
//pour faire un affichage propre et de suivre les éléments sélectionnés
#define MAX_NUMBER_OF_ITEMS 2

class Menu
{
public:
	Menu(float width, float height);

	//"Dessine" le menu sur la fenêtre
	void draw(sf::RenderWindow* window);

	//Gèrent les sélections de éléments de menus via les touches directionnelles "haut" et "bas"
	void MoveUp();
	void MoveDown();

	//Retourne l'élément de menu actuellement sélectionné
	int GetPressedItem();

	//Lance la fenêtre du menu
	void MenuWindow(sf::RenderWindow* window);

private:
	//Permet de connaître l'élément de menu actuel sélectionné
	int selectedItemIndex;
	sf::Font font;
	//Stocke les textes à afficher, ils sont modifiés pour avoir un suivi graphique de l'élément de menu
	//séléctionné
	sf::Text text[MAX_NUMBER_OF_ITEMS];
};

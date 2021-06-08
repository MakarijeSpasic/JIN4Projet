#pragma once
#include "SFML/Graphics.hpp"

//variable globale d�finissant le nombre d'�l�ments de menu � afficher, permet de partager la fen�tre
//pour faire un affichage propre et de suivre les �l�ments s�lectionn�s
#define MAX_NUMBER_OF_ITEMS 2

class Menu
{
public:
	Menu(float width, float height);

	//"Dessine" le menu sur la fen�tre
	void draw(sf::RenderWindow* window);

	//G�rent les s�lections de �l�ments de menus via les touches directionnelles "haut" et "bas"
	void MoveUp();
	void MoveDown();

	//Retourne l'�l�ment de menu actuellement s�lectionn�
	int GetPressedItem();

	//Lance la fen�tre du menu
	void MenuWindow(sf::RenderWindow* window);

private:
	//Permet de conna�tre l'�l�ment de menu actuel s�lectionn�
	int selectedItemIndex;
	sf::Font font;
	//Stocke les textes � afficher, ils sont modifi�s pour avoir un suivi graphique de l'�l�ment de menu
	//s�l�ctionn�
	sf::Text text[MAX_NUMBER_OF_ITEMS];
};

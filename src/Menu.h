#pragma once
#include "SFML/Graphics.hpp"
#include <PersonnageJoueur.h>

//variable globale d�finissant le nombre d'�l�ments de menu � afficher, permet de partager la fen�tre
//pour faire un affichage propre et de suivre les �l�ments s�lectionn�s

class Menu
{
public:

	//"Dessine" le menu sur la fen�tre
	virtual void draw(sf::RenderWindow* window) = 0;

	//G�rent les s�lections de �l�ments de menus via les touches directionnelles "haut" et "bas"
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;

	//Retourne l'�l�ment de menu actuellement s�lectionn�
	int GetPressedItem();
	void InitializeText(std::string text_to_write, int rank_of_display, sf::Color color);

	//Lance la fen�tre du menu
	//Il s'agit de la fonction "template":
	//virtual void MenuWindow(sf::RenderWindow* window) final;
	virtual void MenuWindow(sf::RenderWindow* window, PersonnageJoueur* PJ) final;

	//virtual bool ExecuteElement(int selectedItem, sf::RenderWindow* window) = 0;
	virtual bool ExecuteElement(int selectedItem, sf::RenderWindow* window, PersonnageJoueur* PJ) = 0;

	//il s'agit de la m�thode permettant d'initialiser le texte avec les infos importantes :
	virtual void setText(sf::Text* text, float heightPosition, float widthPosition, std::string textToWrite, int rankInText, sf::Color color, int size);
	
	
	virtual void Update(sf::RenderWindow* window, PersonnageJoueur* PJ) = 0;

protected:
	//Permet de conna�tre l'�l�ment de menu actuel s�lectionn�
	int selectedItemIndex;
	sf::Font font;
};

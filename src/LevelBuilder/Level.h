#pragma once
#include "SFML/Graphics.hpp"
#include <PersonnageJoueur.h>

//variable globale définissant le nombre d'éléments de menu à afficher, permet de partager la fenêtre
//pour faire un affichage propre et de suivre les éléments sélectionnés

class Menu
{
public:

	//"Dessine" le menu sur la fenêtre
	virtual void draw(sf::RenderWindow* window) = 0;

	//Gèrent les sélections de éléments de menus via les touches directionnelles "haut" et "bas"
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;

	//Retourne l'élément de menu actuellement sélectionné
	int GetPressedItem();
	void InitializeText(std::string text_to_write, int rank_of_display, sf::Color color);

	//Lance la fenêtre du menu
	//Il s'agit de la fonction "template":
	//virtual void MenuWindow(sf::RenderWindow* window) final;
	virtual void MenuWindow(sf::RenderWindow* window, PersonnageJoueur* PJ) final;

	//virtual bool ExecuteElement(int selectedItem, sf::RenderWindow* window) = 0;
	virtual bool ExecuteElement(int selectedItem, sf::RenderWindow* window, PersonnageJoueur* PJ) = 0;

	//il s'agit de la méthode permettant d'initialiser le texte avec les infos importantes :
	virtual void setText(sf::Text* text, float heightPosition, float widthPosition, std::string textToWrite, int rankInText, sf::Color color, int size);
	
	
	virtual void Update(sf::RenderWindow* window, PersonnageJoueur* PJ) = 0;

protected:
	//Permet de connaître l'élément de menu actuel sélectionné
	int selectedItemIndex;
	sf::Font font;
};

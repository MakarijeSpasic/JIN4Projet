#pragma once
#include "SFML/Graphics.hpp"
#include "Menu.h"

//variable globale définissant le nombre d'éléments de menu à afficher, permet de partager la fenêtre
//pour faire un affichage propre et de suivre les éléments sélectionnés
#define MAX_NUMBER_OF_ITEMS 7

class Boutique : public Menu
{
public:
	Boutique(float width, float height, PersonnageJoueur* PJ);

	//"Dessine" le menu sur la fenêtre
	void draw(sf::RenderWindow* window) override;

	//Gèrent les sélections de éléments de menus via les touches directionnelles "haut" et "bas"
	void MoveUp() override;
	void MoveDown() override;

	bool ExecuteElement(int selectedItem, sf::RenderWindow* window, PersonnageJoueur* PJ) override;

	void Update(sf::RenderWindow* window, PersonnageJoueur* PJ) override;

	void ExecuteBuy(int price, int range, int speed, int cooldown, PersonnageJoueur* PJ, sf::RenderWindow* window);
	
	//Initialise l'objet sf::text avec les paramètres suivants : 
	// (sf::Text* text, float heightPosition, float widthPosition, std::string textToWrite, int rankInText, sf::Color color, int size)
	void setText(sf::Text* text, float heightPosition, float widthPosition, std::string textToWrite, int rankInText, sf::Color color, int size) override;

	bool TryPay(int prix, PersonnageJoueur* PJ, sf::RenderWindow* window);
	
private:
	//Stocke les textes à afficher, ils sont modifiés pour avoir un suivi graphique de l'élément de menu
	//séléctionné
	sf::Text text[MAX_NUMBER_OF_ITEMS];
};
#pragma once
#include "SFML/Graphics.hpp"
#include "Menu.h"

//variable globale d?finissant le nombre d'?l?ments de menu ? afficher, permet de partager la fen?tre
//pour faire un affichage propre et de suivre les ?l?ments s?lectionn?s
#define MAX_NUMBER_OF_ITEMS 7

class Boutique : public Menu
{
public:
	Boutique(float width, float height, PersonnageJoueur* PJ);

	//"Dessine" le menu sur la fen?tre
	void draw(sf::RenderWindow* window) override;

	//G?rent les s?lections de ?l?ments de menus via les touches directionnelles "haut" et "bas"
	void MoveUp() override;
	void MoveDown() override;

	bool ExecuteElement(int selectedItem, sf::RenderWindow* window, PersonnageJoueur* PJ) override;

	void Update(sf::RenderWindow* window, PersonnageJoueur* PJ) override;

	void ExecuteBuy(int price, int range, int speed, int cooldown, PersonnageJoueur* PJ, sf::RenderWindow* window);
	
	//Initialise l'objet sf::text avec les param?tres suivants : 
	// (sf::Text* text, float heightPosition, float widthPosition, std::string textToWrite, int rankInText, sf::Color color, int size)
	void setText(sf::Text* text, float heightPosition, float widthPosition, std::string textToWrite, int rankInText, sf::Color color, int size) override;

	bool TryPay(int prix, PersonnageJoueur* PJ, sf::RenderWindow* window);
	
private:
	//Stocke les textes ? afficher, ils sont modifi?s pour avoir un suivi graphique de l'?l?ment de menu
	//s?l?ctionn?
	sf::Text text[MAX_NUMBER_OF_ITEMS];
};
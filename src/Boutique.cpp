#include "Boutique.h"
#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <Windows.h>

Boutique::Boutique(float width, float height, PersonnageJoueur* PJ)
{
	//On charge d'abord la police d'�criture depuis le dossier resources, afin d'afficher du texte.
	if (!font.loadFromFile("../../resources/mangat.ttf"))
	{
		//on v�rifie qu'il n'y a pas eu d'erreur lors du chargement de la police d'�criture
		std::cout << "Il y a une erreur dans la police" << std::endl;
	}

	//On initialise les diff�rents textes � afficher sur la page du menu :
	int shop_Height = (height - (height / 4));

	setText(text,
		10 ,
		10 ,
		"Pieces: " + std::to_string(PJ->getPieces()),
		5,
		sf::Color::Yellow,
		25);

	//On s'assure que les pieces sont affich�es en haut � gauche : 
	text[5].setOrigin(0, 0);

	setText(text,
		(shop_Height / (MAX_NUMBER_OF_ITEMS + 1)),
		width/2,
		"100: Arme plus longue (+1) mais moins de vitesse de d�placement",
		0,
		sf::Color::Red, 
		15);


	setText(text,
		(shop_Height / (MAX_NUMBER_OF_ITEMS + 1) * 2),
		width / 2,
		"100: Arme plus courte (-1) mais moins de cooldown",
		1,
		sf::Color::White,
		15);

	setText(text,
		(shop_Height / (MAX_NUMBER_OF_ITEMS + 1) * 3),
		width / 2,
		"100: Arme plus longue (+2) mais plus de cooldwon et moins de vitesse de d�placement",
		2,
		sf::Color::White,
		15);

	setText(text,
		(shop_Height / (MAX_NUMBER_OF_ITEMS + 1) * 4),
		width / 2,
		"100: Arme plus longue (+2) mais plus de cooldown sur l'arme (+2)",
		3,
		sf::Color::White,
		15);

	setText(text,
		(height / 6) * 5,
		width / 2,
		"Retour au jeu",
		4,
		sf::Color::White,
		20);

	setText(text,
		(shop_Height / (MAX_NUMBER_OF_ITEMS + 1) * 5),
		width / 2,
		"",
		6,
		sf::Color::Green,
		25);


	//On initialise le premier "�l�ment du menu" choisi a 0, c'est � dire � play (c'est le bouton qui brillera en premier)
	selectedItemIndex = 0;
}



void Boutique::draw(sf::RenderWindow* window)
{
	//On dessine les diff�rents textes sur la fen�tre
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window->draw(text[i]);
	}
}

void Boutique::MoveUp()
{
	//Il s'agit de la fonction permettant de naviguer entre les �l�ments de menu, ici en allant vers le haut 
	//lorsqu'on appuie sur la touche "haut"
	if (selectedItemIndex - 1 >= 0)
	{
		//On change les couleurs du texte afin d'avoir un affichage graphique coh�rent avec les s�l�ctions actuelles
		text[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		text[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Boutique::MoveDown()
{
	// De m�me que pour MoveUp
	if (selectedItemIndex + 1 <= 4)
	{
		text[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		text[selectedItemIndex].setColor(sf::Color::Red);
	}
}

bool Boutique::ExecuteElement(int selectedItem, sf::RenderWindow* window, PersonnageJoueur* PJ) {
	switch (selectedItem) {

	case 4:
		//Le bouton play a �t� utilis�, on lance/reprend le jeu en mettant le bool�en game_launched � true
		window->clear(sf::Color::Black);
		return true;
		break;

	case 0:
		//Arme plus longue (+1) mais moins de vitesse de d�placement
		ExecuteBuy(100, 0, -0.1, 5, PJ, window);
		return false;
		break;
	case 1:
		//Arme plus courte (-1) mais moins de cooldown
		ExecuteBuy(100, -1, 0, -5, PJ, window);
		return false;
		break;

	case 2:
		//Arme plus longue (+2) mais plus de cooldown et moins de vitesse de d�placement
		ExecuteBuy(100, 1, -0.1, 10, PJ, window);
		return false;
		break;

	case 3:
		//Arme plus longue (+2) mais plus de cooldown sur l'arme (+2)
		ExecuteBuy(100, 2, 0, 10, PJ, window);
		return false;
		break;
	}
}

bool Boutique::TryPay(int prix, PersonnageJoueur* PJ, sf::RenderWindow* window) {
	int PJPieces = PJ->getPieces();
	if (PJPieces >= prix)
	{
		text[6].setString("Achat effectu�");
		text[6].setOrigin(text[6].getLocalBounds().width / 2, text[6].getLocalBounds().height / 2);
		PJ->setPieces(PJPieces - prix);
		text[5].setString("Pieces: " + std::to_string(PJ->getPieces()));
		window->clear(sf::Color::Black);
		window->draw(text[6]);
		window->draw(text[5]);
		return true;
	}
	else {
		text[6].setString("Vous n'avez pas assez de pieces");
		text[6].setOrigin(text[6].getLocalBounds().width / 2, text[6].getLocalBounds().height / 2);
		window->draw(text[6]);
		return false;
	}
}

void Boutique::Update(sf::RenderWindow* window, PersonnageJoueur* PJ) {
	text[5].setString("Pieces: " + std::to_string(PJ->getPieces()));
}

void Boutique::ExecuteBuy(int price, int range, int speed, int cooldown, PersonnageJoueur* PJ, sf::RenderWindow* window) {
	if (TryPay(price, PJ, window)) {
		PJ->SetStats(range, speed, cooldown);
		window->clear(sf::Color::Black);
	}

}

void Boutique::setText(sf::Text* text, float heightPosition, float widthPosition, std::string textToWrite,
	int rankInText, sf::Color color, int size) {
	text[rankInText].setFont(font);
	text[rankInText].setColor(color);
	text[rankInText].setCharacterSize(size);
	text[rankInText].setString(textToWrite);
	text[rankInText].setPosition(sf::Vector2f(widthPosition, heightPosition));
	text[rankInText].setOrigin(text[rankInText].getLocalBounds().width / 2, text[rankInText].getLocalBounds().height / 2);
}
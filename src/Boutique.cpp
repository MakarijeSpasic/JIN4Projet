#include "Boutique.h"
#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <Windows.h>

Boutique::Boutique(float width, float height, PersonnageJoueur* PJ)
{
	//On charge d'abord la police d'écriture depuis le dossier resources, afin d'afficher du texte.
	if (!font.loadFromFile("../../resources/mangat.ttf"))
	{
		//on vérifie qu'il n'y a pas eu d'erreur lors du chargement de la police d'écriture
		std::cout << "Il y a une erreur dans la police" << std::endl;
	}

	//On initialise les différents textes à afficher sur la page du menu :
	int shop_Height = (height - (height / 4));

	setText(text,
		10 ,
		10 ,
		"Pieces: " + std::to_string(PJ->getPieces()),
		5,
		sf::Color::Yellow,
		25);

	//On s'assure que les pieces sont affichées en haut à gauche : 
	text[5].setOrigin(0, 0);

	setText(text,
		(shop_Height / (MAX_NUMBER_OF_ITEMS + 1)),
		width/2,
		"100: Arme plus longue (+1) mais moins de vitesse de déplacement",
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
		"100: Arme plus longue (+2) mais plus de cooldwon et moins de vitesse de déplacement",
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


	//On initialise le premier "élément du menu" choisi a 0, c'est à dire à play (c'est le bouton qui brillera en premier)
	selectedItemIndex = 0;
}



void Boutique::draw(sf::RenderWindow* window)
{
	//On dessine les différents textes sur la fenêtre
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window->draw(text[i]);
	}
}

void Boutique::MoveUp()
{
	//Il s'agit de la fonction permettant de naviguer entre les éléments de menu, ici en allant vers le haut 
	//lorsqu'on appuie sur la touche "haut"
	if (selectedItemIndex - 1 >= 0)
	{
		//On change les couleurs du texte afin d'avoir un affichage graphique cohérent avec les séléctions actuelles
		text[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		text[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Boutique::MoveDown()
{
	// De même que pour MoveUp
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
		//Le bouton play a été utilisé, on lance/reprend le jeu en mettant le booléen game_launched à true
		window->clear(sf::Color::Black);
		return true;
		break;

	case 0:
		//Arme plus longue (+1) mais moins de vitesse de déplacement
		ExecuteBuy(100, 0, -0.1, 5, PJ, window);
		return false;
		break;
	case 1:
		//Arme plus courte (-1) mais moins de cooldown
		ExecuteBuy(100, -1, 0, -5, PJ, window);
		return false;
		break;

	case 2:
		//Arme plus longue (+2) mais plus de cooldown et moins de vitesse de déplacement
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
		text[6].setString("Achat effectué");
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
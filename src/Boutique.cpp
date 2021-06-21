#include "Boutique.h"
#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds


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

	text[5].setFont(font);
	text[5].setColor(sf::Color::Yellow);
	text[5].setString("Pieces: " + std::to_string(PJ->getPieces()));
	text[5].setPosition(sf::Vector2f(10, 10));


	text[0].setFont(font);
	text[0].setColor(sf::Color::Red);
	text[0].setCharacterSize(15);
	text[0].setString("100: Arme plus longue (+1) mais moins de vitesse de déplacement");
	text[0].setPosition(sf::Vector2f(width / 4, shop_Height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	text[1].setFont(font);
	text[1].setCharacterSize(15);
	text[1].setColor(sf::Color::White);
	text[1].setString("100: Arme plus courte (-1) mais moins de cooldown");
	text[1].setPosition(sf::Vector2f(width / 4, shop_Height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	//text[1].setOrigin(text[1].getLocalBounds().left / 2,text[1].getLocalBounds().top/2);

	text[2].setFont(font);
	text[2].setColor(sf::Color::White);
	text[2].setCharacterSize(15);
	text[2].setString("100: Arme plus longue (+2) mais plus de cooldwon et moins de vitesse de déplacement");
	text[2].setPosition(sf::Vector2f(width / 4, shop_Height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	text[3].setFont(font);
	text[3].setColor(sf::Color::White);
	text[3].setCharacterSize(15);
	text[3].setString("100: Arme plus longue (+2) mais plus de cooldown sur l'arme (+2)");
	text[3].setPosition(sf::Vector2f(width / 4, shop_Height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	text[4].setFont(font);
	text[4].setColor(sf::Color::White);
	text[4].setString("Retour au jeu");
	text[4].setPosition(sf::Vector2f(width / 4, (height/6) * 5));

	//Il s'agit du texte préchargé pour le message de la méthode TryPay
	text[6].setFont(font);
	text[6].setColor(sf::Color::Yellow);
	text[6].setPosition(sf::Vector2f(width / 6, (shop_Height / (MAX_NUMBER_OF_ITEMS + 1))));


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
		if (TryPay(100, PJ, window)) {
			if (true) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			//text[6].setString("");
			PJ->SetStats(0, -0.1, 5);
			window->clear(sf::Color::Black);
			return true;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		text[6].setString("");
		return false;
		break;
	case 1:
		//Arme plus courte (-1) mais moins de cooldown
		if (TryPay(100, PJ, window)) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			//text[6].setString("");
			PJ->SetStats(-1, 0, -5);
			window->clear(sf::Color::Black);
			return true;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		text[6].setString("");
		return false;
		break;
	case 2:
		//Arme plus longue (+2) mais plus de cooldown et moins de vitesse de déplacement
		if (TryPay(100, PJ, window)) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			//text[6].setString("");
			PJ->SetStats(1, -0.1, 10);
			window->clear(sf::Color::Black);
			return true;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		text[6].setString("");
		return false;
		break;
	case 3:
		//Arme plus longue (+2) mais plus de cooldown sur l'arme (+2)
		if (TryPay(100, PJ, window)) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			//text[6].setString("");
			PJ->SetStats(2, 0, 10);
			window->clear(sf::Color::Black);
			return true;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		text[6].setString("");
		return false;
		break;
	}
}

bool Boutique::TryPay(int prix, PersonnageJoueur* PJ, sf::RenderWindow* window) {
	int PJPieces = PJ->getPieces();
	if (PJPieces >= prix)
	{
		text[6].setString("Achat effectué");
		PJ->setPieces(PJPieces - prix);
		text[5].setString("Pieces: " + std::to_string(PJ->getPieces()));
		window->clear(sf::Color::Black);
		window->draw(text[6]);
		window->draw(text[5]);
		return true;
	}
	else {
		text[6].setString("Vous n'avez pas assez de pieces");
		window->draw(text[6]);
		return false;
	}
}

void Boutique::Update(sf::RenderWindow* window, PersonnageJoueur* PJ) {
	text[5].setString("Pieces: " + std::to_string(PJ->getPieces()));
}
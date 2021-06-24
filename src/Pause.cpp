#include "Pause.h"
#include <iostream>




Pause::Pause(float width, float height, PersonnageJoueur* PJ)
{
	//On charge d'abord la police d'écriture depuis le dossier resources, afin d'afficher du texte.
	if (!font.loadFromFile("../../resources/mangat.ttf"))
	{
		//on vérifie qu'il n'y a pas eu d'erreur lors du chargement de la police d'écriture
		std::cout << "Il y a une erreur dans la police" << std::endl;
	}

	//On initialise les différents textes à afficher sur la page du menu :

	text[0].setFont(font);
	text[0].setColor(sf::Color::Red);
	text[0].setString("Resume Game");
	text[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	text[1].setFont(font);
	text[1].setColor(sf::Color::White);
	text[1].setString("Exit Game");
	text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	text[2].setFont(font);
	text[2].setColor(sf::Color::Yellow);
	text[2].setString("Pieces: " + std::to_string(PJ->getPieces()));
	text[2].setPosition(sf::Vector2f(10, 10));
	//On initialise le premier "élément du menu" choisi a 0, c'est à dire à play (c'est le bouton qui brillera en premier)
	selectedItemIndex = 0;
}



void Pause::draw(sf::RenderWindow* window)
{
	//On dessine les différents textes sur la fenêtre
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window->draw(text[i]);
	}
}

void Pause::MoveUp()
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

void Pause::MoveDown()
{
	// De même que pour MoveUp
	if (selectedItemIndex + 1 <= MAX_NUMBER_OF_ITEMS - 1)
	{
		text[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		text[selectedItemIndex].setColor(sf::Color::Red);
	}
}

bool Pause::ExecuteElement(int selectedItem, sf::RenderWindow* window, PersonnageJoueur* PJ) {
	switch (selectedItem) {

	case 0:
		//Le bouton play a été utilisé, on reprend le jeu en mettant le booléen game_launched à true
		window->clear(sf::Color::Black);
		return true;
		break;

	case 1:
		//On ferme le jeu si le bouton exit a été séléctionné
		window->close();
		return false;
		break;
	}
}

void Pause::Update(sf::RenderWindow* window, PersonnageJoueur* PJ) {
	text[2].setString("Pieces: " + std::to_string(PJ->getPieces()));
}

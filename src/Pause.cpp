#include "Pause.h"
#include <iostream>




Pause::Pause(float width, float height, PersonnageJoueur* PJ)
{
	//On charge d'abord la police d'�criture depuis le dossier resources, afin d'afficher du texte.
	if (!font.loadFromFile("../../resources/mangat.ttf"))
	{
		//on v�rifie qu'il n'y a pas eu d'erreur lors du chargement de la police d'�criture
		std::cout << "Il y a une erreur dans la police" << std::endl;
	}

	//On initialise les diff�rents textes � afficher sur la page du menu :

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
	//On initialise le premier "�l�ment du menu" choisi a 0, c'est � dire � play (c'est le bouton qui brillera en premier)
	selectedItemIndex = 0;
}



void Pause::draw(sf::RenderWindow* window)
{
	//On dessine les diff�rents textes sur la fen�tre
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window->draw(text[i]);
	}
}

void Pause::MoveUp()
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

void Pause::MoveDown()
{
	// De m�me que pour MoveUp
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
		//Le bouton play a �t� utilis�, on reprend le jeu en mettant le bool�en game_launched � true
		window->clear(sf::Color::Black);
		return true;
		break;

	case 1:
		//On ferme le jeu si le bouton exit a �t� s�l�ctionn�
		window->close();
		return false;
		break;
	}
}

void Pause::Update(sf::RenderWindow* window, PersonnageJoueur* PJ) {
	text[2].setString("Pieces: " + std::to_string(PJ->getPieces()));
}

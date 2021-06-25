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

	setText(text,
		height / (MAX_NUMBER_OF_ITEMS + 1),
		width / 2,
		"Resume Game",
		0,
		sf::Color::Red,
		30);

	setText(text,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 2,
		width / 2,
		"Exit Game",
		1,
		sf::Color::White,
		30);

	setText(text,
		10,
		10,
		"Pieces: " + std::to_string(PJ->getPieces()),
		2,
		sf::Color::Yellow,
		30);

	//On s'assure que les pieces sont affich�es en haut � gauche : 
	text[2].setOrigin(0, 0);

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

void Pause::setText(sf::Text* text, float heightPosition, float widthPosition, std::string textToWrite,
	int rankInText, sf::Color color, int size) {
	text[rankInText].setFont(font);
	text[rankInText].setColor(color);
	text[rankInText].setCharacterSize(size);
	text[rankInText].setString(textToWrite);
	text[rankInText].setPosition(sf::Vector2f(widthPosition, heightPosition));
	text[rankInText].setOrigin(text[rankInText].getLocalBounds().width / 2, text[rankInText].getLocalBounds().height / 2);
}
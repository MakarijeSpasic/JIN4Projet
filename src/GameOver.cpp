#include "GameOver.h"
#include <iostream>




GameOver::GameOver(float width, float height, PersonnageJoueur* PJ)
{
	//On charge d'abord la police d'écriture depuis le dossier resources, afin d'afficher du texte.
	if (!font.loadFromFile("../../resources/mangat.ttf"))
	{
		//on vérifie qu'il n'y a pas eu d'erreur lors du chargement de la police d'écriture
		std::cout << "Il y a une erreur dans la police" << std::endl;
	}

	//On initialise les différents textes à afficher sur la page du menu :

	setText(text,
		height / (MAX_NUMBER_OF_ITEMS + 1),
		width / 2,
		"Game Over",
		0,
		sf::Color::Yellow,
		50);

	setText(text,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 2,
		width / 2,
		"Exit",
		1,
		sf::Color::Red,
		30);

	//On initialise le premier "élément du menu" choisi a 1, le seul qu'il y ait
	selectedItemIndex = 1;
}



void GameOver::draw(sf::RenderWindow* window)
{
	//On dessine les différents textes sur la fenêtre
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window->draw(text[i]);
	}
}

//On ne peut pas bouger dans le menu GameOver, donc il n'y a pas besoin  d'implémenter les méthodes de mouvement:
void GameOver::MoveUp()
{
	//Pas besoin de l'implémenter pour ce menu
}

void GameOver::MoveDown()
{
	//Pas besoin de l'implémenter pour ce menu
}

bool GameOver::ExecuteElement(int selectedItem, sf::RenderWindow* window, PersonnageJoueur* PJ) {
	switch (selectedItem) {
	case 1:
		//On ferme le jeu si on a perdu
		window->close();
		return false;
		break;
	}
}

void GameOver::Update(sf::RenderWindow* window, PersonnageJoueur* PJ) {
}

void GameOver::setText(sf::Text* text, float heightPosition, float widthPosition, std::string textToWrite,
	int rankInText, sf::Color color, int size) {
	text[rankInText].setFont(font);
	text[rankInText].setColor(color);
	text[rankInText].setCharacterSize(size);
	text[rankInText].setString(textToWrite);
	text[rankInText].setPosition(sf::Vector2f(widthPosition, heightPosition));
	text[rankInText].setOrigin(text[rankInText].getLocalBounds().width / 2, text[rankInText].getLocalBounds().height / 2);
}
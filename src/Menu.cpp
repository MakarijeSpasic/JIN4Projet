#include "Menu.h"
#include <iostream>



/*
void Menu::MenuWindow(sf::RenderWindow* window)
{
	//Il s'agit d'un booléen permettant de fermer le menu une fois que le bouton play est activé
	bool game_launched = false;

	//On lance la boucle pour lancer la fenêtre du menu
	while (window->isOpen()) {

		sf::Event event;

		while (window->pollEvent(event))
		{
			switch (event.type) {

			//si la fenêtre est fermée,
			case sf::Event::Closed:
				//On ferme le processus
				window->close();
				break;


			case sf::Event::KeyPressed: //Si une touche est utilisée
				switch (event.key.code) {//Selon la touche enregistrée on fait une action

				//Permet de naviguer dans le menu selon la touche saisie, haut ou bas
				case sf::Keyboard::Up:
					this->MoveUp();
					break;
				case sf::Keyboard::Down:
					this->MoveDown();
					break;

				//on effectue différentes actions en fonction de l'élément de menu sélectionné avec la touche entrée
				case sf::Keyboard::Return:

					//on récupère l'élément de menu sélectionné
					int i = this->GetPressedItem();

					game_launched = this->ExecuteElement(i, window);
				}
				break;

			}
			//On redessine à chaque frame le menu, afin d'avoir les modifications graphiques en temps réel
			window->clear(sf::Color::Black);

			this->draw(window);

			window->display();
		}
		//Si le booléen game_launched est true, c'est a dire que le joueur a choisi de lancer/reprendre le jeu,
		//La boucle gérant la fenêtre de menu s'arrête, et on peut reprendre le jeu dans la fenêtre principale
		if (game_launched) {
			window->clear(sf::Color::Black);
			//On vient d'effacer le menu et on reprend le jeu.
			break;
		}
	}


}
*/

void Menu::MenuWindow(sf::RenderWindow* window, PersonnageJoueur* PJ)
{
	//Il s'agit d'un booléen permettant de fermer le menu une fois que le bouton play est activé
	bool game_launched = false;

	//On lance la boucle pour lancer la fenêtre du menu
	while (window->isOpen()) {

		sf::Event event;

		while (window->pollEvent(event))
		{
			switch (event.type) {

				//si la fenêtre est fermée,
			case sf::Event::Closed:
				//On ferme le processus
				window->close();
				break;


			case sf::Event::KeyPressed: //Si une touche est utilisée
				switch (event.key.code) {//Selon la touche enregistrée on fait une action

				//Permet de naviguer dans le menu selon la touche saisie, haut ou bas
				case sf::Keyboard::Up:
					this->MoveUp();
					break;
				case sf::Keyboard::Down:
					this->MoveDown();
					break;

					//on effectue différentes actions en fonction de l'élément de menu sélectionné avec la touche entrée
				case sf::Keyboard::Return:

					//on récupère l'élément de menu sélectionné
					int i = this->GetPressedItem();

					game_launched = this->ExecuteElement(i, window, PJ);
				}
				break;

			}
			//On redessine à chaque frame le menu, afin d'avoir les modifications graphiques en temps réel
			window->clear(sf::Color::Black);

			this->draw(window);

			window->display();
		}
		//Si le booléen game_launched est true, c'est a dire que le joueur a choisi de lancer/reprendre le jeu,
		//La boucle gérant la fenêtre de menu s'arrête, et on peut reprendre le jeu dans la fenêtre principale
		if (game_launched) {
			window->clear(sf::Color::Black);
			//On vient d'effacer le menu et on reprend le jeu.
			break;
		}
	}


}

int Menu::GetPressedItem()
{
	//Permet de récupérer l'élément de menu sélectionné, pour pouvoir par la suite les traiter dans la fenêtre du menu
	return selectedItemIndex;
}

/*
void InitializeText(std::string text_to_write, int rank_of_display, sf::Color color, sf::Text* text, sf::Font font) {
	text[0].setFont(font);
	text[0].setColor(sf::Color::Red);
	text[0].setString("Arme plus longue (+1) mais moins de vie");
	text[0].setPosition(sf::Vector2f(width / 4, shop_Height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
}
*/
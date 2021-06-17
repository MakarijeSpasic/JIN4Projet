#include "Menu.h"
#include <iostream>



/*
void Menu::MenuWindow(sf::RenderWindow* window)
{
	//Il s'agit d'un bool�en permettant de fermer le menu une fois que le bouton play est activ�
	bool game_launched = false;

	//On lance la boucle pour lancer la fen�tre du menu
	while (window->isOpen()) {

		sf::Event event;

		while (window->pollEvent(event))
		{
			switch (event.type) {

			//si la fen�tre est ferm�e,
			case sf::Event::Closed:
				//On ferme le processus
				window->close();
				break;


			case sf::Event::KeyPressed: //Si une touche est utilis�e
				switch (event.key.code) {//Selon la touche enregistr�e on fait une action

				//Permet de naviguer dans le menu selon la touche saisie, haut ou bas
				case sf::Keyboard::Up:
					this->MoveUp();
					break;
				case sf::Keyboard::Down:
					this->MoveDown();
					break;

				//on effectue diff�rentes actions en fonction de l'�l�ment de menu s�lectionn� avec la touche entr�e
				case sf::Keyboard::Return:

					//on r�cup�re l'�l�ment de menu s�lectionn�
					int i = this->GetPressedItem();

					game_launched = this->ExecuteElement(i, window);
				}
				break;

			}
			//On redessine � chaque frame le menu, afin d'avoir les modifications graphiques en temps r�el
			window->clear(sf::Color::Black);

			this->draw(window);

			window->display();
		}
		//Si le bool�en game_launched est true, c'est a dire que le joueur a choisi de lancer/reprendre le jeu,
		//La boucle g�rant la fen�tre de menu s'arr�te, et on peut reprendre le jeu dans la fen�tre principale
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
	//Il s'agit d'un bool�en permettant de fermer le menu une fois que le bouton play est activ�
	bool game_launched = false;

	//On lance la boucle pour lancer la fen�tre du menu
	while (window->isOpen()) {

		sf::Event event;

		while (window->pollEvent(event))
		{
			switch (event.type) {

				//si la fen�tre est ferm�e,
			case sf::Event::Closed:
				//On ferme le processus
				window->close();
				break;


			case sf::Event::KeyPressed: //Si une touche est utilis�e
				switch (event.key.code) {//Selon la touche enregistr�e on fait une action

				//Permet de naviguer dans le menu selon la touche saisie, haut ou bas
				case sf::Keyboard::Up:
					this->MoveUp();
					break;
				case sf::Keyboard::Down:
					this->MoveDown();
					break;

					//on effectue diff�rentes actions en fonction de l'�l�ment de menu s�lectionn� avec la touche entr�e
				case sf::Keyboard::Return:

					//on r�cup�re l'�l�ment de menu s�lectionn�
					int i = this->GetPressedItem();

					game_launched = this->ExecuteElement(i, window, PJ);
				}
				break;

			}
			//On redessine � chaque frame le menu, afin d'avoir les modifications graphiques en temps r�el
			window->clear(sf::Color::Black);

			this->draw(window);

			window->display();
		}
		//Si le bool�en game_launched est true, c'est a dire que le joueur a choisi de lancer/reprendre le jeu,
		//La boucle g�rant la fen�tre de menu s'arr�te, et on peut reprendre le jeu dans la fen�tre principale
		if (game_launched) {
			window->clear(sf::Color::Black);
			//On vient d'effacer le menu et on reprend le jeu.
			break;
		}
	}


}

int Menu::GetPressedItem()
{
	//Permet de r�cup�rer l'�l�ment de menu s�lectionn�, pour pouvoir par la suite les traiter dans la fen�tre du menu
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
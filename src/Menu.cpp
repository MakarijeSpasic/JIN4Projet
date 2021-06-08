#include "Menu.h"
#include <iostream>




Menu::Menu(float width, float height)
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
	text[0].setString("Play");
	text[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	
	text[1].setFont(font);
	text[1].setColor(sf::Color::White);
	text[1].setString("Exit");
	text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	
	//On initialise le premier "�l�ment du menu" choisi a 0, c'est � dire � play (c'est le bouton qui brillera en premier)
	selectedItemIndex = 0;
}


void Menu::draw(sf::RenderWindow* window)
{
	//On dessine les diff�rents textes sur la fen�tre
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window->draw(text[i]);
	}
}

void Menu::MoveUp()
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

void Menu::MoveDown()
{
	// De m�me que pour MoveUp
	if (selectedItemIndex + 1 <= MAX_NUMBER_OF_ITEMS)
	{
		text[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		text[selectedItemIndex].setColor(sf::Color::Red);
	}
}

int Menu::GetPressedItem()
{
	//Permet de r�cup�rer l'�l�ment de menu s�lectionn�, pour pouvoir par la suite les traiter dans la fen�tre du menu
	return selectedItemIndex;
}

void Menu::MenuWindow(sf::RenderWindow* window)
{
	//tentative de mettre le menu dans une fen�tre rectangulaire blanche, ne marche pas 
	sf::RectangleShape menuSquare(sf::Vector2f(window->getSize().x*(3/4),window->getSize().y*(3/4)));
	menuSquare.setFillColor(sf::Color::White);

	//Il s'agit d'un bool�en permettant de fermer le menu une fois que le bouton play est activ�
	bool game_launched = false;

	//On lance la boucle pour lancer la fen�tre du menu
	while (window->isOpen()) {

		sf::Event event;

		//on dessine le rectangle servant de support au menu : ne marche pas
		window->draw(menuSquare);

		while (window->pollEvent(event))
		{
			switch (event.type) {

			//si la fen�tre est ferm�e,
			case sf::Event::Closed:
				//On ferme le processus
				window->close();
				break;


			case sf::Event::KeyPressed: //Si une touche est utilis�e
				std::cout << "Une touche a �t� utilis�e" << std::endl;
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

					switch (i) {

					case 0:
						//Le bouton play a �t� utilis�, on lance/reprend le jeu en mettant le bool�en game_launched � true
						window->clear(sf::Color::Black);
						game_launched = true;
						break;

					case 1:
						//On ferme le jeu si le bouton exit a �t� s�l�ctionn�
						window->close();
						break;
					}
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

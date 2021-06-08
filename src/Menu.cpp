#include "Menu.h"
#include <iostream>



sf::Font font;
Menu::Menu(float width, float height)
{
	/*
	if (!font.loadFromFile("C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/resources/mangat.ttf")) 
	{
		//on vérifie qu'il n'y a pas eu d'erreur lors du chargement de la police d'écriture
		std::cout << "Il y a une erreur dans la police" << std::endl;
	}
	*/
	//Cette version est correcte et devrait marcher pour tout le monde, mais ce n'est pas le cas, le "working directory" ne semble pas être Tmxlite_SampleSFML/build
	
	if (!font.loadFromFile("../../resources/mangat.ttf"))
	{
		//on vérifie qu'il n'y a pas eu d'erreur lors du chargement de la police d'écriture
		std::cout << "Il y a une erreur dans la police" << std::endl;
	}
	
	text[0].setFont(font);
	text[0].setColor(sf::Color::Red);
	text[0].setString("Play");
	text[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	

	text[1].setFont(font);
	text[1].setColor(sf::Color::White);
	text[1].setString("Options");
	text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	text[2].setFont(font);
	text[2].setColor(sf::Color::White);
	text[2].setString("Exit");
	text[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	
	selectedItemIndex = 0;
}


void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(text[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		text[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		text[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 <= MAX_NUMBER_OF_ITEMS)
	{
		text[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		text[selectedItemIndex].setColor(sf::Color::Red);
	}
}

int Menu::GetPressedItem()
{
	return selectedItemIndex;
}

void Menu::MenuWindow(sf::RenderWindow* window)
{
	sf::RectangleShape menuSquare(sf::Vector2f(window->getSize().x*(3/4),window->getSize().y*(3/4)));
	menuSquare.setFillColor(sf::Color::White);
	bool game_launched = false;
	while (window->isOpen()) {
		sf::Event event;
		window->draw(menuSquare);
		while (window->pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				window->close();
				break;


			case sf::Event::KeyPressed: //Si une touche est utilisée
				std::cout << "Une touche a été utilisée" << std::endl;
				switch (event.key.code) {//Selon la touche enregistrée on fait une action
				case sf::Keyboard::Up:
					this->MoveUp();
					break;
				case sf::Keyboard::Down:
					this->MoveDown();
					break;
				case sf::Keyboard::Return:
					int i = this->GetPressedItem();
					switch (i) {
					case 0:
						//std::cout << "Le bouton Play a été utilisé" << std::endl;
						window->clear(sf::Color::Black);
						game_launched = true;
						//return;
						break;
					case 1:
						//std::cout << "Le bouton 2 a été utilisé" << std::endl;
						break;
					case 2:
						//std::cout << "Le bouton exit a été utilisé" << std::endl;
						window->close();
						break;
					}
				}
				break;

			}
			window->clear(sf::Color::Black);
			this->draw(*window);

			window->display();
		}
		if (game_launched) {
			window->clear(sf::Color::Black);
			//std::cout << "le dessin est effacé" << std::endl;
			break;
		}
	}
}

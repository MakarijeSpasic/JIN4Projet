/* Adaptation of https://github.com/fallahn/tmxlite/blob/master/SFMLExample/src/main.cpp :
    - #include "SFMLOrthogonalLayer.hpp"
      becomes
      #include "SFMLOrthogonalLayer.h"
    - int main()
      becomes
      int myMain()
    - map.load("assets/demo.tmx");
      becomes
      map.load("resources/demo.tmx");
*/
/*********************************************************************
(c) Matt Marchant & contributors 2016 - 2019
http://trederia.blogspot.com
tmxlite - Zlib license.
This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.
2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#include <iostream>
#include <string>
#include <filesystem>
#include <direct.h>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::current_path;

#include "myMain.h"
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"



int myMain()
{
    //Pour avoir le chemin du working directory :
    /*
    char tmp[256];
    getcwd(tmp, 256);
    cout << "Current working directory: " << tmp << endl;

    return EXIT_SUCCESS;
    */
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    tmx::Map map;
    map.load("resources/demo.tmx");

    MapLayer layerZero(map, 0);
    MapLayer layerOne(map, 1);
    MapLayer layerTwo(map, 2);

    sf::Clock globalClock;

    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Blue);

    b2Vec2 gravity(0.f, 0.f); //Pas de gravité
    b2World world(gravity);

    PersonnageJoueur joueur(&world,30,60, 1, 10, 1, 1, 1);
    //Les limites du monde sont donc 0 à 80 sur x et 0 à 60 sur y


     //On crée le menu
    Menu menu(window.getSize().x, window.getSize().y);

    //On appelle d'abord le menu pour lancer le menu avant de lancer le jeu
    menu.MenuWindow(&window);
    window.clear(sf::Color::Black);
    CustomQueryCallback query;

    while (window.isOpen())
    {
        
        joueur.UpdateWindowPosition();
        joueur.UpdateDirection();

        //printf("player win pos = %f ; %f \n", joueur.GetShape().getPosition().x, joueur.GetShape().getPosition().y);
        //printf("player wrld pos = %f ; %f \n", joueur.GetBody()->GetPosition().x, joueur.GetBody()->GetPosition().y);

       
        sf::Event event;
        sf::Time duration = globalClock.getElapsedTime();
        while (window.pollEvent(event))
        {
            
            switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;
            
            
            case sf::Event::KeyPressed: //Si une touche est pressed
                switch (event.key.code) {//Selon la touche pressed on fait une action
                
                case sf::Keyboard::Left:
                    joueur.Deplacer(duration.asSeconds() * b2Vec2(-1, 0)); //Il faut transmettre le timestep dans la fonction pour déplacer à la juste distance
                    break;
                case sf::Keyboard::Right:
                    joueur.Deplacer(duration.asSeconds() * b2Vec2(1, 0));
                    break;
                case sf::Keyboard::Up:
                    joueur.Deplacer(duration.asSeconds() * b2Vec2(0, 1));
                    break;
                case sf::Keyboard::Down:
                    joueur.Deplacer(duration.asSeconds() * b2Vec2(0, -1));
                    break;
                case sf::Keyboard::Space:
                    break;
                }
                break;
            
            }
        }


        layerZero.update(duration);

        world.Step(duration.asSeconds(), 6, 2);

        window.clear(sf::Color::Black);
        menu.draw(window);
        
        /*
        window.draw(layerZero);
        window.draw(layerOne);
        window.draw(layerTwo);

        window.draw(shape);
        */

        window.draw(joueur.GetShape());


        window.display();
    }

    return 0;
}

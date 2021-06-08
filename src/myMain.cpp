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
#include <CustomQueryCallback.h>



int myMain()
{
    //Pour avoir le chemin du working directory :
    /*
    char tmp[256];
    getcwd(tmp, 256);
    cout << "Current working directory: " << tmp << endl;

    return EXIT_SUCCESS;
    */
    sf::RenderWindow window(sf::VideoMode(800, 608), "SFML window");

    //On crée un objet map qu'on charge avec le fichier .tmx qui contient la carte à afficher
    tmx::Map map;
    map.load("../../resources/embedmap.tmx");
    
    //On charge le layer afin de le dessiner plus tard
    MapLayer layerZero(map, 0);

    sf::Clock globalClock;

    //Test pour voir si quelque chose s'affiche
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Blue);

    b2Vec2 gravity(0.f, 0.f); //Pas de gravit�
    b2World world(gravity);

    PersonnageJoueur joueur(&world,30.f,60.f, 1, 1, 1, 1, 10);
    //Les limites du monde sont donc 0 a 80 sur x et 0 a 60 sur y


    //On crée l'objet menu avec la taille de la fenêtre de jeu, pour assurer le bon affichage du texte
    Menu menu(window.getSize().x, window.getSize().y);

    //On ouvre d'abord le menu, il s'agit de la première fenêtre qui s'affiche avant le jeu
    menu.MenuWindow(&window);
    window.clear(sf::Color::Black);
    PlayerQueryCallback callback;

    int i = 0;

    while (window.isOpen())
    {
        
        //On update la position du joueur à chaque frame
        joueur.UpdateWindowPosition();
        

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
                    joueur.Move(duration.asSeconds() * b2Vec2(-1, 0)); //Il faut transmettre le timestep dans la fonction pour d�placer � la juste distance
                    joueur.UpdateDirection(b2Vec2(-1, 0));
                    printf("player direction = %f ; %f \n", joueur.GetDirection().x, joueur.GetDirection().y);
                    break;
                case sf::Keyboard::Right:
                    joueur.Move(duration.asSeconds() * b2Vec2(1, 0));
                    joueur.UpdateDirection(b2Vec2(1, 0));
                    printf("player direction = %f ; %f \n", joueur.GetDirection().x, joueur.GetDirection().y);
                    break;
                case sf::Keyboard::Up:
                    joueur.Move(duration.asSeconds() * b2Vec2(0, 1));
                    joueur.UpdateDirection(b2Vec2(0, 1));
                    printf("player direction = %f ; %f \n", joueur.GetDirection().x, joueur.GetDirection().y);
                    break;
                case sf::Keyboard::Down:
                    joueur.Move(duration.asSeconds() * b2Vec2(0, -1));
                    joueur.UpdateDirection(b2Vec2(0, -1));
                    printf("player direction = %f ; %f \n", joueur.GetDirection().x, joueur.GetDirection().y);
                    break;
                case sf::Keyboard::Space:
                    joueur.Attack(&world, &callback);
                    break;

                //On lance le menu si la touche échap est utilisée
                case sf::Keyboard::Escape:
                    menu.MenuWindow(&window);
                    break;
                }
                break;
            
            }
        }


        layerZero.update(duration);

        world.Step(duration.asSeconds(), 6, 2);

        window.clear(sf::Color::Black);
        menu.draw(window);
        
        //On dessine la carte .tsx chargée dans le layerZero
        window.draw(layerZero);

        //On dessine le joueur en récupérant sa forme
        window.draw(joueur.GetShape());

        if (joueur.isAttacking()) {
            printf("player attacks ! \n");
            window.draw(joueur.GetSword());
            printf("player win pos = %f ; %f \n", joueur.GetShape().getPosition().x, joueur.GetShape().getPosition().y);
            printf("sword position = %f,%f \n", joueur.GetSword().getPosition().x, joueur.GetSword().getPosition().y);
            printf("sword size = %f,%f \n", joueur.GetSword().getSize().x, joueur.GetSword().getSize().y);
            joueur.setAttacking(false);
        }
        


        window.display();

        i++;
    }

    return 0;
}

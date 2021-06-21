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

#define ATTACK_FRAMES 100


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

    PersonnageJoueur joueur(&world,40.f,30.f, 10, 1, 1000, 0.2, 10); // world, wrld_x,wrld_y,health,force,cooldown,speed,range
    //Les limites du monde sont donc 0 a 80 sur x et 0 a 60,8 sur y

    //On va créer des murs

    
    b2BodyDef murOuestBodyDef;
    murOuestBodyDef.position.Set(0.0f, 30.0f);
    b2Body* murOuestBody = world.CreateBody(&murOuestBodyDef);
    b2PolygonShape murOuestBox;
    murOuestBox.SetAsBox(1.0f, 50.0f);
    murOuestBody->CreateFixture(&murOuestBox, 0.0f);
    
    b2BodyDef murEstBodyDef;
    murEstBodyDef.position.Set(87.0f, 30.0f);
    b2Body* murEstBody = world.CreateBody(&murEstBodyDef);
    b2PolygonShape murEstBox;
    murEstBox.SetAsBox(10.0f, 50.0f);
    murEstBody->CreateFixture(&murEstBox, 0.0f);
    
    b2BodyDef murNordBodyDef;
    murNordBodyDef.position.Set(40.0f, 70.0f);
    b2Body* murNordBody = world.CreateBody(&murNordBodyDef);
    b2PolygonShape murNordBox;
    murNordBox.SetAsBox(50.0f, 10.0f);
    murNordBody->CreateFixture(&murNordBox, 0.0f);
    
    b2BodyDef murSudBodyDef;
    murSudBodyDef.position.Set(40.0f, -7.0f);
    b2Body* murSudBody = world.CreateBody(&murSudBodyDef);
    b2PolygonShape murSudBox;
    murSudBox.SetAsBox(60.0f, 10.0f);
    murSudBody->CreateFixture(&murSudBox, 0.0f);
    
    Monstre monstre_a(&world, 10, Monstre1,29.f, 30.f, 1, 1);
    Monstre monstre_b(&world, 10, Monstre2, 10.f, 20.f, 1, 1);
    Monstre monstre_c(&world, 10, Monstre3, 10.f, 40.f, 1, 1);


    //On crée les menus de la boutique, de l'écran de démarrage et de pause :
    EcranAcceuil startWindow(window.getSize().x, window.getSize().y);
    Pause pauseWindow(window.getSize().x, window.getSize().y);
    Boutique shopWindow(window.getSize().x, window.getSize().y);

    //On ouvre d'abord le menu, il s'agit de la première fenêtre qui s'affiche avant le jeu
    startWindow.MenuWindow(&window, &joueur);
    window.clear(sf::Color::Black);
    
    //Listeners
    MyContactListener contactListener;

    joueur.initFont();
    joueur.initHPBar();
    
    int attack_countdown = 0;


    while (window.isOpen())
    {
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
                    joueur.Move(b2Vec2(-1, 0)); //Il faut transmettre le timestep dans la fonction pour d�placer � la juste distance
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
                    if (joueur.GetCanAttack()) {

                        joueur.Attack();
                        attack_countdown = joueur.GetCooldown();
                        printf("monstre a = %d PV\n", monstre_a.GetHealth());
                    }
                    break;

                //On lance le menu si la touche échap est utilisée
                case sf::Keyboard::Escape:
                    pauseWindow.MenuWindow(&window, &joueur);
                    break;
                case sf::Keyboard::P:
                    shopWindow.MenuWindow(&window, &joueur);
                    break;
                }
                break;
            
            }
        }

        //On update la position du joueur à chaque frame
        joueur.updateHPBar();
        joueur.UpdateWindowPosition();
        monstre_a.UpdateWindowPosition();
        monstre_b.UpdateWindowPosition();
        monstre_c.UpdateWindowPosition();

        layerZero.update(duration);

        world.Step(duration.asSeconds(), 6, 2);

        window.clear(sf::Color::Black);
        //startWindow.draw(&window);
        
        //On dessine la carte .tsx chargée dans le layerZero
        window.draw(layerZero);

        //On dessine le joueur en récupérant sa forme
        window.draw(joueur.GetShape());

        //On dessine la barre de vie du joueur
        joueur.renderHPBar(&window);


        if (attack_countdown > 0) {
            //printf("player attacks ! \n");
            window.draw(joueur.GetSword());
            //printf("player win pos = %f ; %f \n", joueur.GetShape().getPosition().x, joueur.GetShape().getPosition().y);
            //printf("sword position = %f,%f \n", joueur.GetSword().getPosition().x, joueur.GetSword().getPosition().y);
            //printf("sword size = %f,%f \n", joueur.GetSword().getSize().x, joueur.GetSword().getSize().y);
            
            attack_countdown--;
            
        }
        else {
            joueur.setCanAttack(true);
        }
        
        window.draw(monstre_a.GetShape());
        window.draw(monstre_b.GetShape());
        window.draw(monstre_c.GetShape());
        


        window.display();

        
    }

    return 0;
}

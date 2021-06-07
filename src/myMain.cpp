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



#include "myMain.h"
#include <stdio.h>
#include <stdlib.h>



int myMain()
{
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

    PersonnageJoueur joueur(&world,30.f,60.f, 1, 1, 1, 1, 10);
    //Les limites du monde sont donc 0 à 80 sur x et 0 à 60 sur y

    PlayerQueryCallback callback;

    int i = 0;

    while (window.isOpen())
    {
        
        joueur.UpdateWindowPosition();
        

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
                    joueur.UpdateDirection(b2Vec2(-1, 0));
                    printf("player direction = %f ; %f \n", joueur.GetDirection().x, joueur.GetDirection().y);
                    break;
                case sf::Keyboard::Right:
                    joueur.Deplacer(duration.asSeconds() * b2Vec2(1, 0));
                    joueur.UpdateDirection(b2Vec2(1, 0));
                    printf("player direction = %f ; %f \n", joueur.GetDirection().x, joueur.GetDirection().y);
                    break;
                case sf::Keyboard::Up:
                    joueur.Deplacer(duration.asSeconds() * b2Vec2(0, 1));
                    joueur.UpdateDirection(b2Vec2(0, 1));
                    printf("player direction = %f ; %f \n", joueur.GetDirection().x, joueur.GetDirection().y);
                    break;
                case sf::Keyboard::Down:
                    joueur.Deplacer(duration.asSeconds() * b2Vec2(0, -1));
                    joueur.UpdateDirection(b2Vec2(0, -1));
                    printf("player direction = %f ; %f \n", joueur.GetDirection().x, joueur.GetDirection().y);
                    break;
                case sf::Keyboard::Space:
                    joueur.Attaquer(&world, &callback);
                    
                    
                    break;
                }
                break;
            
            }
        }


        
        layerZero.update(duration);

        world.Step(duration.asSeconds(), 6, 2);
        if (i >= 100) {
            window.clear(sf::Color::Black);
            i = 0;
        }
        window.draw(layerZero);
        window.draw(layerOne);
        window.draw(layerTwo);

        window.draw(shape);
        
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

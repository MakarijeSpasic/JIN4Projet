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

    b2Vec2 gravity(0.f, -1.f);
    b2World world(gravity);

    PersonnageJoueur joueur(&world,30,60, 1, 1, 1, 1, 1);
    //Les limites du monde sont donc 0 à 80 sur x et 0 à 60 sur y
    

    while (window.isOpen())
    {
        
        joueur.UpdateWindowPosition();

        //printf("player win pos = %f ; %f \n", joueur.GetShape().getPosition().x, joueur.GetShape().getPosition().y);
        //printf("player wrld pos = %f ; %f \n", joueur.GetBody()->GetPosition().x, joueur.GetBody()->GetPosition().y);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time duration = globalClock.getElapsedTime();
        layerZero.update(duration);

        world.Step(duration.asSeconds(), 6, 2);

        window.clear(sf::Color::Black);

        window.draw(layerZero);
        window.draw(layerOne);
        window.draw(layerTwo);

        window.draw(shape);
        
        window.draw(joueur.GetShape());


        window.display();
    }

    return 0;
}

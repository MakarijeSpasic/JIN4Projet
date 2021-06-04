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


#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

#include <tmxlite/Map.hpp>

#include "SFMLOrthogonalLayer.h"

//Ici on met nos include concernant le perso et les monstres

#include "Entite.h"
#include "PersonnageJoueur.h"

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

    PersonnageJoueur joueur(0, 1, 1, 1, 10, 20, 10);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time duration = globalClock.getElapsedTime();
        layerZero.update(duration);

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

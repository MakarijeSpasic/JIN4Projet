#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "SFMLOrthogonalLayer.h"

#include <tmxlite/Map.hpp>

#include "box2d/box2d.h"

//Ici on met nos include concernant le perso et les monstres

#include "Entite.h"
#include "PersonnageJoueur.h"
#include "PlayerQueryCallback.h"
#include "Menu.h"
#include <MyContactListener.h>



int myMain();
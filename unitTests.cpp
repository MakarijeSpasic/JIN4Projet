#include <gtest/gtest.h>


#include "PersonnageJoueur.h"
#include "Monstre.h"

#include <iostream>
#include <string>
#include <filesystem>
#include <direct.h>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::current_path;


#include <stdio.h>
#include <stdlib.h>

#include <PlayerQueryCallback.h>

b2Vec2 gravity(0.f, 0.f); //Pas de gravite
b2World world(gravity);

PlayerQueryCallback callback;
PersonnageJoueur joueur(&world, 40.f, 30.f, 1, 1, 1, 1, 100);//On met une très grande portee pour etre sur de toucher l'ennemi
Monstre monstre_a(&world, 10, Monstre1, 41.f, 30.f, 1, 1); //On cree un monstre juste a coté et on le tape

TEST(Player, AttackZone) {
	joueur.Move(0.01 * b2Vec2(1, 0));

}

TEST(Player, Attack) {

	
	//On se rapproche d'un monstre et on attaque
	
	joueur.Attack(&world, &callback);

	EXPECT_EQ(monstre_a.GetHealth(), 0);
}

TEST(Player, Hurt) {

	//On fonce sur un monstre, on recule et on regarde si on a perdu de la vie
	joueur.Move(0.01 * b2Vec2(1, 0));
	joueur.Move(0.01 * b2Vec2(-1, 0));

	EXPECT_NE(joueur.GetHealth(), 1);

}



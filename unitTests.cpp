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
#include <Boutique.h>

b2Vec2 gravity(0.f, 0.f); //Pas de gravite
b2World world(gravity);

PlayerQueryCallback callback;
PersonnageJoueur joueur(&world, 40.f, 30.f, 1, 1, 1, 1, 100,100);//On met une très grande portee pour etre sur de toucher l'ennemi
Monstre monstre_a(&world, 10, Monstre1, 41.f, 30.f, 1, 1); //On cree un monstre juste a coté et on le tape

TEST(Player, AttackZone) {
	joueur.Move(0.01 * b2Vec2(1, 0));

}

TEST(Player, Attack) {

	
	//On se rapproche d'un monstre et on attaque
	
	joueur.Attack();

	EXPECT_EQ(monstre_a.GetHealth(), 0);
}

TEST(Player, Hurt) {

	//On fonce sur un monstre, on recule et on regarde si on a perdu de la vie
	joueur.Move(0.01 * b2Vec2(1, 0));
	joueur.Move(0.01 * b2Vec2(-1, 0));

	EXPECT_NE(joueur.GetHealth(), 1);

}


TEST(Boutique, Transaction) {
	sf::RenderWindow window;
	int initPieces = 100;
	int prix = 100;
	b2Vec2 gravity(0.f, 0.f); //Pas de gravite
	b2World world(gravity);
	PersonnageJoueur joueur(&world, 0, 0, 0, 0, 0, 0, 0, initPieces);//Seul l'argent du personnage nous intéresse ici
	Boutique shopWindow(window.getSize().x, window.getSize().y, &joueur);
	bool resultTry = shopWindow.TryPay(prix, &joueur, &window);
	EXPECT_EQ(resultTry, true);
	bool resultExec = shopWindow.ExecuteElement(0,&window,&joueur);
	EXPECT_EQ(resultExec, true);
	//résultat attendu pour le premier élément : prix -100, range +0, speed -0.1, cooldown +5
	EXPECT_EQ(joueur.getPieces(), initPieces - prix);
	EXPECT_EQ(joueur.GetCooldown(), 5);

}

TEST(Boutique, Transaction2) {
	sf::RenderWindow window;
	int initPieces = 100;
	int prix = 100;
	b2Vec2 gravity(0.f, 0.f); //Pas de gravite
	b2World world(gravity);
	PersonnageJoueur joueur(&world, 0, 0, 0, 0, 0, 0, 0, initPieces);//Seul l'argent du personnage nous intéresse ici
	Boutique shopWindow(window.getSize().x, window.getSize().y, &joueur);
	bool resultTry = shopWindow.TryPay(prix, &joueur, &window);
	EXPECT_EQ(resultTry, true);
	bool resultExec = shopWindow.ExecuteElement(0, &window, &joueur);
	EXPECT_EQ(resultExec, true);
	//résultat attendu pour le premier élément : prix 100, range -1, speed 0, cooldown -5,
	EXPECT_EQ(joueur.getPieces(), initPieces - prix);
	EXPECT_EQ(joueur.GetCooldown(), -5);

}
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
#include <MyContactListener.h>


TEST(Player, AttackZone) {
	

	b2Vec2 gravity(0.f, 0.f); //Pas de gravite
	b2World world(gravity);

	                             // wrldx, wrldy, health, force, cooldown, speed, range, pieces
	PersonnageJoueur joueur(&world, 0.f, 0.f, 10, 1, 1000, 0.2, 10, 100);
	Monstre monstre(&world, 10, Monstre1, 2.f, 30.f, 1, 1);

	MyContactListener contactListener;
	world.SetContactListener(&contactListener);

	joueur.Move(1 / 60 * b2Vec2(1, 0));
	joueur.Move(1 / 60 * b2Vec2(1, 0));//Histoire d'être sûr que le joueur touche le monstre
	joueur.Attack();
	EXPECT_EQ(monstre.GetHealth(), 0);
	EXPECT_EQ(joueur.GetHealth(), 0);

}


TEST(Boutique, Transaction) {
	sf::RenderWindow window;
	int initPieces = 100;
	int prix = 100;
	b2Vec2 gravity(0.f, 0.f); //Pas de gravite
	b2World world(gravity);
	PersonnageJoueur joueur(&world, 0, 0, 0, 0, 5, 0, 0, initPieces);//Seul l'argent du personnage nous intéresse ici
	Boutique shopWindow(window.getSize().x, window.getSize().y, &joueur);
	bool resultTry = shopWindow.TryPay(prix, &joueur, &window);
	EXPECT_EQ(resultTry, true);
	bool resultExec = shopWindow.ExecuteElement(0,&window,&joueur);
	EXPECT_EQ(resultExec, false);
	//résultat attendu pour le premier élément : prix -100, range +1, speed -0.1, cooldown 0
	EXPECT_EQ(joueur.getPieces(), initPieces - prix);
	EXPECT_EQ(joueur.GetCooldown(), 5);
	//EXPECT_EQ(joueur.GetSword().getSize().x, 1);
}

TEST(Boutique, Transaction2) {
	sf::RenderWindow window;
	int initPieces = 100;
	int prix = 100;
	b2Vec2 gravity(0.f, 0.f); //Pas de gravite
	b2World world(gravity);
	//On vérifie la range et le cooldown du personnage
	PersonnageJoueur joueur(&world, 0, 0, 0, 0, 5, 0, 1, initPieces);
	Boutique shopWindow(window.getSize().x, window.getSize().y, &joueur);
	bool resultTry = shopWindow.TryPay(prix, &joueur, &window);
	EXPECT_EQ(resultTry, true);
	bool resultExec = shopWindow.ExecuteElement(1, &window, &joueur);
	EXPECT_EQ(resultExec, false);
	//résultat attendu pour le deuxième élément : prix 100, range -1, speed 0, cooldown -5,
	EXPECT_EQ(joueur.getPieces(), initPieces - prix);
	EXPECT_EQ(joueur.GetCooldown(), 5);

}
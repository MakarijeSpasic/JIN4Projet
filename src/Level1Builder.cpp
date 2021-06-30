#include "Level1Builder.h"
#include <iostream>


Level1Builder::Level1Builder() {
	this->reset();
}

//Réinitilialise le builder
void Level1Builder::reset() {
	this->level = new Level();
}

Level1Builder::~Level1Builder() {
	delete level;
}

//Permet de récupérer les variables map, où la map a été chargée depuis le fichier tmx, et MapToDraw, correspondant au layer de décor à dessiner (1 seul layer)
void Level1Builder::setMap() {
	level->Map = new tmx::Map();
	level->Map->load("../../resources/embedmap.tmx");

	//On charge le layer à dessiner plus tard
	level->MapToDraw = new MapLayer(*(level->Map), 0);
}

// Permet d'initialiser la position du joueur dans le niveau créé
void Level1Builder::setPlayerPosition() {
	level->InitPlayerX = 40.f;
	level->InitPlayerY = 30.f;
}

//Permet d'initialiser les monstres avec leurs positions et de les rattacher au world,
//Est appelé dans myMain pour placer les monstres
void Level1Builder::setMonsters(b2World* world) {
	Monstre monstre_a(world, 10, Monstre1, 29.f, 30.f, 1, 1);
	Monstre monstre_b(world, 10, Monstre2, 10.f, 20.f, 1, 1);
	Monstre monstre_c(world, 10, Monstre3, 10.f, 40.f, 1, 1);
	std::vector<Monstre> monsters{monstre_a,monstre_b,monstre_c };
	level->monsters = monsters;
}

//permet de récupérer le level
Level* Level1Builder::getLevel() {
	Level* result = level;
	reset();
	return result;
}

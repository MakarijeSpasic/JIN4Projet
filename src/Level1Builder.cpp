#include "Level1Builder.h"
#include <iostream>


Level1Builder::Level1Builder() {
	this->reset();
}

//R�initilialise le builder
void Level1Builder::reset() {
	this->level = new Level();
}

Level1Builder::~Level1Builder() {
	delete level;
}

//Permet de r�cup�rer les variables map, o� la map a �t� charg�e depuis le fichier tmx, et MapToDraw, correspondant au layer de d�cor � dessiner (1 seul layer)
void Level1Builder::setMap() {
	level->Map = new tmx::Map();
	level->Map->load("../../resources/embedmap.tmx");

	//On charge le layer � dessiner plus tard
	level->MapToDraw = new MapLayer(*(level->Map), 0);
}

// Permet d'initialiser la position du joueur dans le niveau cr��
void Level1Builder::setPlayerPosition() {
	level->InitPlayerX = 40.f;
	level->InitPlayerY = 30.f;
}

//Permet d'initialiser les monstres avec leurs positions et de les rattacher au world,
//Est appel� dans myMain pour placer les monstres
void Level1Builder::setMonsters(b2World* world) {
	Monstre monstre_a(world, 10, Monstre1, 29.f, 30.f, 1, 1);
	Monstre monstre_b(world, 10, Monstre2, 10.f, 20.f, 1, 1);
	Monstre monstre_c(world, 10, Monstre3, 10.f, 40.f, 1, 1);
	std::vector<Monstre> monsters{monstre_a,monstre_b,monstre_c };
	level->monsters = monsters;
}

//permet de r�cup�rer le level
Level* Level1Builder::getLevel() {
	Level* result = level;
	reset();
	return result;
}

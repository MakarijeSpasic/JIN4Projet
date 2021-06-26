#include "Level2Builder.h"
#include <iostream>


Level2Builder::Level2Builder() {
	this->reset();
}

//Réinitilialise le Level2Level2Builder
void Level2Builder::reset() {
	this->level = new Level();
}

Level2Builder::~Level2Builder() {
	delete level;
}

void Level2Builder::setMap() {
	level->Map = new tmx::Map();
	level->Map->load("../../resources/embedmap.tmx");

	//On charge le layer à dessiner plus tard
	level->MapToDraw = new MapLayer(*(level->Map), 0);
}

void Level2Builder::setPlayerPosition() {
	level->InitPlayerX = 40.f;
	level->InitPlayerY = 30.f;
}

void Level2Builder::setMonsters(b2World* world) {
	Monstre monstre_a(world, 10, Monstre1, 29.f, 30.f, 1, 1);
	Monstre monstre_b(world, 10, Monstre2, 10.f, 20.f, 1, 1);
	Monstre monstre_c(world, 10, Monstre3, 10.f, 40.f, 1, 1);
	std::vector<Monstre> monsters = { monstre_a,monstre_b,monstre_c };
	level->monsters = monsters;
}

Level* Level2Builder::getLevel() {
	Level* result = level;
	reset();
	return result;
}
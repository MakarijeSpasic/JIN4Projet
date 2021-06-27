#include <LevelDirector.h>

void LevelDirector::BuildLevel(b2World* world){
	builder->setMap();
	builder->setPlayerPosition();
	builder->setMonsters(world);
	}

void LevelDirector::setBuilder(LevelBuilder* givenBuilder) {
	this->builder = givenBuilder;
}
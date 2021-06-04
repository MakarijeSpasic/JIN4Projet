#pragma once
#include <box2d/b2_body.h>

class Entite
{
public:
	Entite(int x, int y, int givenHealth);
	void attaque() const;

protected:
	b2Body body;
	int health;
};


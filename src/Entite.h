#pragma once
class Entite
{
public:
	Entite(int x, int y, int givenHealth);
	virtual ~Entite() = 0;
	int attaque() const;
protected:
	current_coord coord;
	int health;
};

struct current_coord {
	int x;
	int y;
};
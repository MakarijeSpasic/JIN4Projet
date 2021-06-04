#pragma once
struct current_coord {
	int x;
	int y;
};

class Entite
{
public:
	Entite(int x, int y, int givenHealth);
	void attaque() const;
protected:
	struct current_coord coord;
	int health;
};


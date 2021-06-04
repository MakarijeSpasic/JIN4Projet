#pragma once
struct current_coord {
	int x;
	int y;
};

class Entite
{
public:
	Entite(int x, int y, int givenHealth);
	virtual ~Entite() = 0;
	int attaque() const;
protected:
	struct current_coord coord;
	int health;
};


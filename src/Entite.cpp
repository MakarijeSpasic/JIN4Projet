#include "Entite.h"

Entite::Entite(int x, int y, int givenHealth) 
	:health(givenHealth)
{
	coord.x = x;
	coord.y = y;
}
int Entite::attaque() const {
	return 1;
}
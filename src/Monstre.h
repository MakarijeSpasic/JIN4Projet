#pragma once
#include "Entite.h"
#include <string>

class Monstre :
	public Entite
{
public:
	Monstre(int zoneActivation, std::string typeMonstre);

protected:
	int zoneActivation;
	std::string typeMonstre;
};


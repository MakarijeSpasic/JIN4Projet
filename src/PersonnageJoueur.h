#pragma once
#include "Entite.h"
#include "Monstre.h"

#include <string>
#include <PlayerQueryCallback.h>
class PlayerQueryCallback; //Faut que j'include et que je fasse ça à la fois pour que ça compile



#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#define MAX_HEALTH 100;



class PersonnageJoueur : public Entite
{
public:
	
	PersonnageJoueur(b2World* world, float wrld_x, float wrld_y, int health,int force, int cooldown, float speed, int range, int pieces);
	
	void Move(b2Vec2 dir);
	void Attack();
	
	void LoseRange(TypeMonstre type);
	void LoseForce(TypeMonstre type); //N'override pas la fonction LoseForce de Entite car l'utilise pour modifier la force


	//M�thodes pour les attaques
	void UpdateDirection(b2Vec2 dir);
	b2AABB GetAABB() { return attackBox; };
	sf::RectangleShape GetSword() { return sword; };
	bool GetCanAttack() { return canAttack; };
	void setCanAttack(bool v) { canAttack = v; };

	b2Vec2 GetDirection() { return direction; };

	int GetCooldown() { return cooldown; };
	int setCooldown(int c) { cooldown = c; };

	//gestion de la barre de vie:
	
	void SetStats(int cooldown_modif, float speed_modif, int range_modif);
	void updateHPBar();
	void renderHPBar(sf::RenderWindow* window);
	void initFont();
	void initHPBar();
	

	int getPieces();
	void setPieces(int newPieces);

protected:
	int cooldown;
	float speed;
	int range;
	
	//Pour les attaques
	std::unique_ptr<PlayerQueryCallback> callback; //Pour lancer les queries necessaire pour distribuer les attaques
	b2Vec2 direction;
	b2AABB attackBox;
	sf::RectangleShape sword;
	bool canAttack;

	
private:
	sf::Font font;
	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarInside;
	//il s'agit de l'argent que le joueur possède
	int pieces;
};


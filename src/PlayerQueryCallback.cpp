#include "PlayerQueryCallback.h"
#include <stdio.h>
#include <stdlib.h>


PlayerQueryCallback::PlayerQueryCallback()
{
    owner = NULL;
}

PlayerQueryCallback::PlayerQueryCallback(PersonnageJoueur* owner):owner(owner){}

void PlayerQueryCallback::SetOwner(PersonnageJoueur* new_owner)
{
    owner = new_owner;
}

bool PlayerQueryCallback::ReportFixture(b2Fixture* fixture)
{

    b2Body* body = fixture->GetBody();
    Monstre* hit = (Monstre*)body->GetUserData().pointer;
    if (hit != NULL and !hit->GetIsPlayer()) { //Si hit est NULL �a veut dire qu'on a touch� un mur, on �vite les bugs facilement.
        //On verifie aussi que c'est bien un monstre car l'attaque, malgr� le fait que le joueur n'est pas dans la zoned d'attaque, semble le toucher quand m�me
        hit->LoseHealth(owner->GetForce());
        owner->LoseRange(hit->GetType());
        owner->LoseForce(hit->GetType());
        //printf("touch�\n");
    }
    
   
    return true;

}

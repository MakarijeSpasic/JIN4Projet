#include "PlayerQueryCallback.h"

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
    if (hit != NULL) { //Si hit est NULL �a veut dire qu'on a touch� un mur, on �vite les bugs facilement
        hit->LoseHealth(owner->GetForce());
    }
    
   
    return true;

}

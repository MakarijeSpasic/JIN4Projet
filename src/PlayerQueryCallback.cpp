#include "PlayerQueryCallback.h"




bool PlayerQueryCallback::ReportFixture(b2Fixture* fixture)
{

    b2Body* body = fixture->GetBody();
    Monstre* hit = (Monstre*)body->GetUserData().pointer;
    hit->LoseHealth(1);
    //Normalement à la place du 1 on met owner->GetForce() pour infliger le bon dommage
    //owner->Lose_damage(hit->GetType());
    // Return true to continue the query.
    return true;

}

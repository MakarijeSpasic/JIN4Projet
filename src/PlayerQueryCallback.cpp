#include "PlayerQueryCallback.h"




bool PlayerQueryCallback::ReportFixture(b2Fixture* fixture)
{

    b2Body* body = fixture->GetBody();
    Monstre* hit = (Monstre*)body->GetUserData().pointer;
    hit->Lose_health(1);//owner->GetForce());
    //owner->Lose_damage(hit->GetType());
    // Return true to continue the query.
    return true;

}

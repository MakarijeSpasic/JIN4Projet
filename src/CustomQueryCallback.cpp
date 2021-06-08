#include "CustomQueryCallback.h"


CustomQueryCallback::CustomQueryCallback(Entite entite):b2QueryCallback(),owner(&entite)
{
}

bool CustomQueryCallback::ReportFixture(b2Fixture* fixture)
{
 
    b2Body* body = fixture->GetBody();
    Entite* hit = (Entite*)body->GetUserData().pointer;
    hit->Lose_health(owner->GetForce());
    // Return true to continue the query.
    return true;

}

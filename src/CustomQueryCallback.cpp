#include "CustomQueryCallback.h"


bool CustomQueryCallback::ReportFixture(b2Fixture* fixture)
{
 
    b2Body* body = fixture->GetBody();
    body->SetAwake(true);

    // Return true to continue the query.
    return true;

}

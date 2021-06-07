#pragma once
#include "box2d/box2d.h"

class CustomQueryCallback : public b2QueryCallback
{
public:
    bool ReportFixture(b2Fixture* fixture);
};


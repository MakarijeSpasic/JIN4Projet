#pragma once

#include "box2d/box2d.h"

class MyContactListener : public b2ContactListener {

public:

	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);

};
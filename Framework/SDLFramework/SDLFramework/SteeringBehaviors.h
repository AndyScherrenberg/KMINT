#pragma once
#include "Vector2D.h"

class SteeringBehaviors
{
public:
	SteeringBehaviors();
	~SteeringBehaviors();

	Vector2D Calculate();

	Vector2D Pursuit(Vector2D& vector);
	Vector2D Flee(Vector2D& vector);
	Vector2D Wander(Vector2D& vector);
    
    bool EntityIsInSpace();
};
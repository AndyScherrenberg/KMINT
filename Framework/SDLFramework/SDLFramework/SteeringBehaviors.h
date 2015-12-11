#pragma once
#include "Vector2D.h"


class MovingEntitiy;
class SteeringBehaviors
{
private:
	MovingEntitiy* owner;

public:
	SteeringBehaviors(MovingEntitiy* owner){
		this->owner = owner;
	}
	~SteeringBehaviors();

	Vector2D Calculate();

	Vector2D Pursuit(Vector2D& vector);
	Vector2D Flee(Vector2D& vector);
	Vector2D Wander(Vector2D& vector);
    
    bool EntityIsInSpace();
};
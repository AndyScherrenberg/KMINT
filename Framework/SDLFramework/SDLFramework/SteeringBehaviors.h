#pragma once
#include "Vector2D.h"


class MovingEntity;
class SteeringBehaviors
{
private:
    MovingEntity* owner;

public:
	SteeringBehaviors(MovingEntity* owner){
		this->owner = owner;
	}
	~SteeringBehaviors();

	Vector2D Calculate();

	Vector2D Seek(const Vector2D& vector);
    Vector2D Pursuit();
	Vector2D Flee();
	Vector2D Wander();
    bool EntityIsInSpace();
};
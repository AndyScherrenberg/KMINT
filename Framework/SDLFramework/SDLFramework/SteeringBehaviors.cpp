#include "SteeringBehaviors.h"


SteeringBehaviors::SteeringBehaviors()
{
}


SteeringBehaviors::~SteeringBehaviors()
{
}


Vector2D SteeringBehaviors::Calculate()
{
	Vector2D vector;

	return vector;
}

Vector2D SteeringBehaviors::Pursuit(Vector2D& vector)
{
	return vector;
}

Vector2D SteeringBehaviors::Flee(Vector2D& vector)
{
	return vector;
}
Vector2D SteeringBehaviors::Wander(Vector2D& vector)
{
	return vector;
}

bool SteeringBehaviors::EntityIsInSpace(){
    return false;
}
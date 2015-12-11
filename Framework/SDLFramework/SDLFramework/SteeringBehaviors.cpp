#include "SteeringBehaviors.h"
#include "MovingEntity.hpp"
#include "CowEntity.h"
#include "SDL.h"

SteeringBehaviors::~SteeringBehaviors()
{
}


Vector2D SteeringBehaviors::Calculate()
{

	switch ( owner->getStateId())
	{
	case 1:
		return this->Pursuit(); 
		break;
	case 2:
		//return this->Wander();
		break;
	case 3:
		//return this->Flee();
		break;
	default:
		break;
	}

	Vector2D vector{ 1, 1 };
	return vector;
}

Vector2D SteeringBehaviors::Seek( const Vector2D& TargetPos)
{

	Vector2D DesiredVelocity; 
	DesiredVelocity = DesiredVelocity.NormalizeVector(TargetPos - owner->getPostion())
		* owner->getMaxSpeed();
	return (DesiredVelocity - owner->getVelocity());

}

Vector2D SteeringBehaviors::Pursuit()
{
	Vector2D ToEvader = owner->getTarget()->getPostion() - owner->getPostion();
	double RelativeHeading = owner->getHeading().Dot(owner->getTarget()->getHeading());
	if ((ToEvader.Dot(owner->getHeading()) > 0) &&
		(RelativeHeading < -0.95))  //acos(0.95)=18 degs
	{
		return Seek(owner->getTarget()->getPostion());
	}
	//Not considered ahead so we predict where the evader will be.
	//the look-ahead time is proportional to the distance between the evader
	//and the pursuer; and is inversely proportional to the sum of the
	//agents' velocities
	double LookAheadTime = ToEvader.Length() /
		(owner->getMaxSpeed() + owner->getTarget()->getSpeed());
	//now seek to the predicted future position of the evader
	return Seek(owner->getTarget()->getPostion() + owner->getTarget()->getVelocity() * LookAheadTime);
}

Vector2D SteeringBehaviors::Flee()
{
	return Vector2D{ 1, 1 };
}

bool SteeringBehaviors::EntityIsInSpace(){
    float xCor = owner->getPostion().getX();
    float yCor = owner->getPostion().getY();
    int screenX = 800;
    int screenY = 600;
    
    if(xCor > screenX + 50 || xCor < -50 || yCor > screenY + 50 || yCor < -50){
        return true;
    }
   
    return false;
}

Vector2D SteeringBehaviors::Wander()
{
	return Vector2D{ 1, 1 };
}
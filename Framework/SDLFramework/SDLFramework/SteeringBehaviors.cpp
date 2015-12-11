#include "SteeringBehaviors.h"
#include "MovingEntity.hpp"
#include "CowEntity.h"

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
		return this->Wander();
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

Vector2D SteeringBehaviors::Seek(Vector2D& TargetPos)
{

	Vector2D DesiredVelocity= NormalizeVector(TargetPos - owner->getPostion())
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



Vector2D SteeringBehaviors::Wander()
{
	double JitterThisTimeSlice = m_dWanderJitter * owner->TimeElapsed();


	m_vWanderTarget += Vector2D(RandomClamped() * m_dWanderJitter,
		RandomClamped() * m_dWanderJitter);


	//reproject this new vector back on to a unit circle
//

	
	m_vWanderTarget = NormalizeVector(m_vWanderTarget);

	//increase the length of the vector to the same as the radius
	//of the wander circle
	m_vWanderTarget *= m_dWanderRadius;

	//move the target into a position WanderDist in front of the agent
	//Vector2D target = m_vWanderTarget + Vector2D(m_dWanderDistance, 0);

	//project the target into world space
	Vector2D Target = PointToWorldSpace(m_vWanderTarget,
		owner->getHeading(),
		owner->getSide(),
		owner->getPostion());
		
	
	//and steer towards it
	return m_vWanderTarget - owner->getPostion();
}

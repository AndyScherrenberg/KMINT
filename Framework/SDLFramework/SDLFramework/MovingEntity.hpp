//
//  MovingEntity.hpp
//  KMINT
//
//  Created by Bryan Sijs on 04-12-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#ifndef MovingEntity_hpp
#define MovingEntity_hpp

#include "IGameObject.h"
#include <stdio.h>
#include "Vector2D.h"

class SteeringBehaviors;

class MovingEntitiy : public IGameObject{
protected:
	int id;
	
	SteeringBehaviors* steering;

	Vector2D postion;
	Vector2D velocity;
	Vector2D heading;
	Vector2D side;

	float mass;
	float maxSpeed;
	float maxForce;

	MovingEntitiy* target;
	double                m_dTimeElapsed;
	int stateId = 0; 
	//1 Pursuit
	//2 Wander
	//3 Flee

public:
	virtual void Update(float deltatime);
	void Draw();
	void setId(int id){ this->id = id; }
	int getId(){ return this->id; }

	double getSpeed()const{ return velocity.Length(); }
	void setSteering(SteeringBehaviors* steering){ this->steering = steering; }
	SteeringBehaviors* getSteering(){ return steering; }

	void setPosition(const Vector2D& postion){ this->postion = postion; }
	Vector2D getPostion(){ return this->postion; }

	void setVelocity(Vector2D& velocity){ this->velocity = velocity; }
	Vector2D getVelocity(){ return this->velocity; }

	void setHeading(Vector2D& heading){ this->heading = heading; }
	Vector2D getHeading(){ return this->heading; }


	Vector2D getSide(){ return this->side; }
	void setMass(float mass){ this->mass = mass; }
	float getMass(){ return this->mass; }

	void setMaxForce(float maxForce){ this->maxForce = maxForce; }
	float getMaxForce(){ return this->maxForce; }

	void setMaxSpeed(float maxSpeed){ this->maxSpeed = maxSpeed; }
	float getMaxSpeed(){ return this->maxSpeed; }

	void SetTarget(MovingEntitiy* entity){ this->target = entity; };
		MovingEntitiy* getTarget(){ return target; }

		void setStateid(int stateId){ this->stateId = stateId; }
		int getStateId(){ return this->stateId; }

		double       TimeElapsed()const{ return m_dTimeElapsed; }
};

#endif /* MovingEntity_hpp */

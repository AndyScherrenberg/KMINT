//
//  MovingEntity.cpp
//  KMINT
//
//  Created by Bryan Sijs on 04-12-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "MovingEntity.hpp"


void MovingEntitiy::Update(double deltaTime)
{
	Vector2D steeringforce = getSteering()->Calculate();

	Vector2D acceleration = steeringforce / getMass();

	velocity += acceleration * deltaTime;

	//Hier moeten we trunctate;
	
	postion += velocity * deltaTime;
}
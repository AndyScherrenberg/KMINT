//
//  MovingEntity.cpp
//  KMINT
//
//  Created by Bryan Sijs on 04-12-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "MovingEntity.hpp"



void MovingEntitiy::Update(float deltaTime)
{
	Vector2D steeringforce = getSteering()->Calculate(); //Hiet moet nog een goed getal komen : D
	steeringforce = Vector2D(1, 2);
	Vector2D acceleration = steeringforce / getMass();

	velocity += acceleration * deltaTime;

	velocity.Trunctate(maxSpeed);

	postion += velocity * deltaTime;

	if (velocity.LenghtSq() > 0.00000001)
	{
		heading = velocity.NormalizeVector(velocity);
		
		side  = heading.Perp();
	}

	
	//WrapAround(this->postion, SDL_GetWindowSurface(this->mApplication->GetWindow())->w, SDL_GetWindowSurface(this->mApplication->GetWindow())->h);
	


	
}

void MovingEntitiy::Draw()
{
	mApplication->DrawTexture(this->GetTexture(), this->getPostion().getX(), this->getPostion().getY(), 50, 50);
}


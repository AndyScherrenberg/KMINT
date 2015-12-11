//
//  MovingEntity.cpp
//  KMINT
//
//  Created by Bryan Sijs on 04-12-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "MovingEntity.hpp"
#include "GameWorld.hpp"
#include "SteeringBehaviors.h"

MovingEntity::MovingEntity(GameWorld* gameworld){
    this->gameWorld = gameworld;
}
MovingEntity::~MovingEntity(){
    
}


void MovingEntity::Update(float deltaTime)
{
	Vector2D steeringforce = getSteering()->Calculate(); //Hiet moet nog een goed getal komen : D

	Vector2D acceleration = steeringforce / getMass();

	velocity += acceleration * deltaTime;

	velocity.Trunctate(maxSpeed);
	
	postion += velocity * deltaTime;

	if (velocity.LenghtSq() > 0.00000001)
	{
		heading = velocity.NormalizeVector(velocity);
		
		side  = heading.Perp();
	}

	if(getSteering()->EntityIsInSpace())
    {
        this->gameWorld->UpdateEntity(this);
    }
	//WrapAround(this->postion, SDL_GetWindowSurface(this->mApplication->GetWindow())->w, SDL_GetWindowSurface(this->mApplication->GetWindow())->h);
}

void MovingEntity::Draw()
{
	mApplication->DrawTexture(this->GetTexture(), this->getPostion().getX(), this->getPostion().getY(), 50, 50);
}


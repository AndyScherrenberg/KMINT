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
//#include <SDL.h>

MovingEntity::MovingEntity(GameWorld* gameworld){
    this->gameWorld = gameworld;
}
MovingEntity::~MovingEntity(){
    
}

void MovingEntity::Update(float deltaTime)
{


	TagNeighbors(120);
	m_dTimeElapsed = deltaTime;

	Vector2D steeringforce = getSteering()->Calculate(); //Hiet moet nog een goed getal komen : D

	Vector2D acceleration = steeringforce / getMass();

	velocity += acceleration * deltaTime;

	velocity.Trunctate(maxSpeed);
	
	postion += velocity * deltaTime;

	if (velocity.LenghtSq() > 0.00000001)
	{
		heading = NormalizeVector(velocity);
		
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

MovingEntity* MovingEntity::getClosestTarget(){
	std::vector<CowEntity*>::iterator it;
	std::vector<CowEntity*> collection = gameWorld->getCowList();
	

	for (std::vector<CowEntity*>::iterator it =collection.begin(); it != collection.end(); ++it){
        /* std::cout << *it; ... */
        if(this->target == nullptr){
            this->target = (*it);
        }
        else if(getPostion().DistanceSq((*it)->getPostion()) < getPostion().DistanceSq(target->getPostion())){
            this->target = (*it);
        }
    }
    return this->target;
}


void MovingEntity::TagNeighbors(double radius)
{
	std::vector<CowEntity*>::iterator it;
	std::vector<CowEntity*> collection = gameWorld->getCowList();

	for (std::vector<CowEntity*>::iterator it = collection.begin(); it != collection.end(); ++it){
			//first clear any current tag
			(*it)->UnTag();
			Vector2D to = (*it)->getPostion() - this->getPostion();
			//the bounding radius of the other is taken into account by adding it
			//to the range
			double range = radius + (*it)->getBRadius();
			//if entity within range, tag for further consideration. (working in
			//distance-squared space to avoid sqrts)
			if (((*it) != this) && (to.LengthSq() < range*range))
			{
				(*it)->Tag();
			}
		}//next entity
	
}

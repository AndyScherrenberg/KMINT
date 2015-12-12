#include "CowEntity.h"
#include "SteeringBehaviors.h"
#include "GameWorld.hpp"
#include <random>
CowEntity::CowEntity(GameWorld* world):MovingEntity(world)
{

	srand(time(NULL));

	/* generate secret number between 1 and 10: */

	int cow = world->getCowList().size() + 1;

	while (cow > 7)cow -= 7;


std::string location =""; 

#ifdef __APPLE__
location = "/Users/bryansijs/Documents/C++/KMINT/KMINT/Framework/SDLFramework/Resources/";

#endif


switch (cow)
{
case 1:
	location = location + "cow-1.png";
	break;
case 2:
	location = location + "cow-2.png";
	break;
case 3:
	location = location + "cow-3.png";
	break;
case 4:
	location = location + "cow-4.png";
	break;
case 5:
	location = location + "cow-5.png";
	break;
case 6:
	location = location + "cow-6.png";
	break;
case 7:
	location = location + "cow-7.png";
	break;
}

	this->SetTexture(mApplication->LoadTexture(location));

	this->setSteering(new SteeringBehaviors{ this });
	this->setStateid(1);
	this->setMaxSpeed(100);
	this->setMass(.4f);
	mApplication->AddRenderable(this);
	world->addCowToCowList(this);
	this->SetTarget(world->getRabbit());
}


CowEntity::~CowEntity()
{
}

void CowEntity::Update(float deltaTime)
{

	MovingEntity::Update(deltaTime);

}


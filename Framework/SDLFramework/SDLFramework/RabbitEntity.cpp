#include "RabbitEntity.h"


RabbitEntity::RabbitEntity(GameWorld* world):MovingEntity(world)
{
#ifdef __APPLE__
	this->SetTexture(mApplication->LoadTexture("/Users/bryansijs/Documents/C++/KMINT/KMINT/Framework/SDLFramework/Resources/haas.png"));
#else
	this->SetTexture(mApplication->LoadTexture("haas.png"));
#endif
	this->setPosition(Vector2D{ 300, 300 });
	this->setMaxSpeed(100);
	this->setMass(.05f);
}


RabbitEntity::~RabbitEntity()
{
}


void RabbitEntity::Update(double deltaTime)
{

}
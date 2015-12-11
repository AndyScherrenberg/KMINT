#include "CowEntity.h"


CowEntity::CowEntity()
{
#ifdef __APPLE__
	this->SetTexture(mApplication->LoadTexture("/Users/bryansijs/Documents/C++/KMINT/KMINT/Framework/SDLFramework/Resources/cow-2.png"));
#else
	this->SetTexture(mApplication->LoadTexture("cow-2.png"));
#endif
	this->setPosition(Vector2D{ 250, 250 });
	this->setMaxSpeed(100);
	this->setMass(.2f);
}


CowEntity::~CowEntity()
{
}

void CowEntity::Update(float deltaTime)
{
	MovingEntitiy::Update(deltaTime);
}
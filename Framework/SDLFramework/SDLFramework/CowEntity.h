#pragma once
#include "MovingEntity.hpp"

class GameWorld;
class CowEntity : public MovingEntity
{
public: 

	//const double keepClose = 50.0 * 50.0;


	CowEntity(GameWorld* world);
	~CowEntity();
	virtual void Update(float deltatime);
};


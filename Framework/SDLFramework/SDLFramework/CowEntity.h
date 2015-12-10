#pragma once
#include "MovingEntity.hpp"


class CowEntity : public MovingEntitiy
{
public: 
	CowEntity();
	~CowEntity();
	virtual void Update(float deltatime);
};


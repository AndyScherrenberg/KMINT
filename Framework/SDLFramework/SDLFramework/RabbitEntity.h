#pragma once
#include "MovingEntity.hpp"



class RabbitEntity : public MovingEntitiy
{
public:
	RabbitEntity();
	~RabbitEntity();
	virtual void Update(double deltatime);
};


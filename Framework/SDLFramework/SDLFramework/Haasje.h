#pragma once
#include "Beestje.h"
#include "BaseState.hpp"

class Haasje : public Beestje
{
public:
	Haasje();
	~Haasje();
	virtual void Draw() override;
	virtual void Update(float deltaTime) override;


};


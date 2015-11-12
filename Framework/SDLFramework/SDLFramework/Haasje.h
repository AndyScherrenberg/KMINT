#pragma once
#include "Beestje.h"

class Haasje : public Beestje
{
public:
	Haasje();
	~Haasje();
	virtual void Draw() override;
	virtual void Update(float deltaTime) override;


};


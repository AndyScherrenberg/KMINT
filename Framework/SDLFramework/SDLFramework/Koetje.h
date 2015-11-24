#pragma once
#include "Beestje.h"
#include "BaseState.hpp"


class Koetje: public Beestje
{
    
public:
	Koetje();
	~Koetje();
	int usedBoots = 0;
	virtual void Draw() override;
	virtual void Update(float deltaTime) override;
};


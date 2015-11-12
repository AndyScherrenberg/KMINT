#pragma once
#include "Beestje.h"
class Koetje: public Beestje
{
public:
	Koetje();
	~Koetje();

	virtual void Draw() override;
	virtual void Update(float deltaTime) override;

};


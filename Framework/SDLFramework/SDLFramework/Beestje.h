#pragma once
#include "IGameObject.h"

class Beestje : public IGameObject
{
public:
	Beestje();
	~Beestje();

	virtual void Draw() override;
	virtual void Update(float deltaTime) override;




};


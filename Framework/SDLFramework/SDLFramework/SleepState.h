#pragma once
#include "BaseState.hpp"
class SleepState : public BaseState

{
public: 
	SleepState();
	~SleepState();

	SleepState(Beestje* beestje, NodeMap* nodemap);

	int sleepTurn = 2;
	int sleepAmount = 0;

	const char* stateToText() override { return "Sleeping"; };
	void Update() override;
	void checkState() override;
};


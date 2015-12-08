#include "SleepState.h"

SleepState::SleepState(Beestje* beestje, NodeMap* nodemap) : BaseState(beestje, nodemap){
	sleepTurn = 2;
}


SleepState::~SleepState()
{
}


void SleepState::checkState(){
	sleepAmount++;
}

void SleepState::Update(){
	if (sleepAmount >= sleepTurn){
		if (dynamic_cast<Haasje*>(owner))
			dynamic_cast<Haasje*>(owner)->sleepChance += 20;
	//	owner->CalculateChance(true);

		owner->setState(StateFactory::createNextState(owner->NextState(), owner, nodeMap));
	}
}
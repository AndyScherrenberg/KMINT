#pragma once
#include "IGameObject.h"
#include "Node.h"
#include <map>

#ifndef Beestje_hpp
#define Beestje_hpp

class Node;
class BaseState;

class Beestje : public IGameObject
{



public:
	Beestje();
	~Beestje();

	virtual void Draw() override;
	virtual void Update(float deltaTime) override;
	virtual void SetBoots(){ hasBoots = !hasBoots; };
	bool getBoots(){ return hasBoots; }
	void setState(BaseState* state){ this->currentState = state; };
	BaseState* getState(){ return currentState; };

	Node* getNode(){ return currentNode; };
	void setNode(Node* node){ this->currentNode = node; };

	std::map<int, int> StateMap; // Goes from state to state
	//  1, 2 means from wandering to drug
	int getWander(){ return wanderAmount; };
	void setWander(int wanderAmount){ this->wanderAmount = wanderAmount; }
	int currentStateid = 1;

	int NextState(){
		auto search = StateMap.find(currentStateid);
		if (search != StateMap.end()) {
			currentStateid = search->second;
			return search->second;
		}
		return 1;
	}

	void setTarget(Beestje* target){ this->target = target; }
	Beestje* getTarget(){ return this->target; }

private:
	bool hasBoots = false;
	Node* currentNode;
	int wanderAmount = 1;
	Beestje* target;
protected:
	BaseState* currentState;
};
#endif


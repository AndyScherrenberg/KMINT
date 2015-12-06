#pragma once
#include "IGameObject.h"
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

	std::multimap<int, int> StateMap; // Goes from state to state
	//  1, 2 means from wandering to drug
	int getWander(){ return wanderAmount; };
	void setWander(int wanderAmount){ this->wanderAmount = wanderAmount; }


	virtual int NextState(){
		auto search = StateMap.find(currentStateId);
		if (search != StateMap.end()) {
			currentStateId = search->second;
			return search->second;
		}
		return 1;
	}


	virtual void CalculateChance(bool positive){};

	void setTarget(Beestje* target){ this->target = target; }
	Beestje* getTarget(){ return this->target; }

	void setBaseSate(int baseStateId)
	{
		currentStateId = baseStateId;
		this->baseStateId = baseStateId;
	}

	int getBaseState()
	{
		return this->baseStateId;
	}

	void setCurrentStateId(int currentStateId){ this->currentStateId = currentStateId; }


	int getCurrentStateId()
	{
		return this->currentStateId;
	}

	int getBadDrugState(){
		return this->badDrugState;
	}
	void setBadDrugState(int badDrugState){ this->badDrugState = badDrugState; }

	void increaseCaught(){ caughtAmount++; }
	int getCaught(){ return caughtAmount; }


	
private:
	bool hasBoots = false;
	Node* currentNode;
	int wanderAmount = 1;
	int baseStateId = 1;
	int currentStateId = 1;
	int badDrugState = -1;
	int caughtAmount = 0;
	Beestje* target;
protected:
	BaseState* currentState;
};
#endif


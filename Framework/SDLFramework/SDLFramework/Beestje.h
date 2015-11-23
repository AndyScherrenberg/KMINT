#pragma once
#include "IGameObject.h"
#include "Node.h"


#ifndef Beestje_hpp
#define Beestje_hpp

class Node;
class CowState;

class Beestje : public IGameObject
{
private:
	bool hasWeapon = false;
public:
	Beestje();
	~Beestje();

	virtual void Draw() override;
	virtual void Update(float deltaTime) override;
	virtual void GiveWeapon(){ hasWeapon = true; };
    void setState(CowState* state){this->currentState  =state;};
    CowState* getState(){return currentState;};
    
	Node* getNode(){ return currentNode; };
	void setNode(Node* node){ this->currentNode = node; };
    
private:
    
	Node* currentNode;
protected:
    CowState* currentState;
};
#endif


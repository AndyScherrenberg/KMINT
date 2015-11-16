#pragma once
#include "IGameObject.h"
#include "Node.h"

class Node;

class Beestje : public IGameObject
{
public:
	Beestje();
	~Beestje();

	virtual void Draw() override;
	virtual void Update(float deltaTime) override;


	Node* getNode(){ return currentNode; };
	void setNode(Node* node){ this->currentNode = node; };
private: 
	Node* currentNode;


};


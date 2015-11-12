#pragma once
#include "Node.h"
#include "IGameObject.h"

class Node;

class Edge: public IGameObject
{
public:
	Edge(Node* node1, Node* node2, int weight);
	~Edge();
	Edge();

	virtual void Draw() override;
	virtual void Update(float deltaTime) override;

	void setNode1(Node* node){
		this->nodeA = node;
	}


	void setNode2(Node* node){
		this->nodeB = node;
	}


	
private:
	Node* nodeA;
	Node* nodeB;
	int weight;
};


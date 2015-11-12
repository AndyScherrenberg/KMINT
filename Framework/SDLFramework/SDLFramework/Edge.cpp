#include "Edge.h"


Edge::Edge()
{
}


Edge::~Edge()
{
}


Edge::Edge(Node* node1, Node* node2, int weight){
	this->setNode1(node1);
	this->setNode2(node2);
	this->weight = weight;

	this->nodeA->addEgde(this);
	this->nodeB->addEgde(this);

	mApplication->SetColor(Color(0, 0, 0, 255));


}

void Edge::Draw(){

	mApplication->DrawLine(nodeA->x, nodeA->y, nodeB->x, nodeB->y);
	mApplication->DrawText(std::to_string(weight), (nodeA->x + nodeB->x) / 2, (nodeA->y + nodeB->y) / 2 - 16);
}
void Edge::Update(float deltaTime) {}
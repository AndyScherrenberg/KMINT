#pragma once
#include "Node.h"


class Node;
class Edge
{
public:
	Edge();
	~Edge();

private:
	Node* node1;
	Node* node2;
	int weight;
};


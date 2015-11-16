#pragma once
#include <map>
#include <list>
#include "Node.h"

class AlgoRitmeWeek1
{
public:
	AlgoRitmeWeek1();
	~AlgoRitmeWeek1();

	void doAction(Node* currentnode, std::vector<Node*> collection);
	bool doAlgoritme(std::map<Node*, int> &edgeWeight, std::map<Node *, Node *> &fromTo);
};


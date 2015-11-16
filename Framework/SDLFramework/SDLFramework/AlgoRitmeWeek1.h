#pragma once
#include <map>
#include <list>
#include "Node.h"

class AlgoRitmeWeek1
{
public:
	AlgoRitmeWeek1();
	~AlgoRitmeWeek1();

	void doAction(Node* currentnode);
	bool doAlgoritme(std::map<Node*, int> &mapRoomWeight, std::map<Node *, Node *> &fromTo);
};


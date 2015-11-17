#pragma once
#include <map>
#include <list>
#include "Node.h"
#include "Koetje.h"
#include "Haasje.h"

class AlgoRitmeWeek1
{
public:
	AlgoRitmeWeek1();
	~AlgoRitmeWeek1();
    void setNewCawPlace(Node* newPlace, Koetje* koe);
	void doAction(Koetje* koe, std::vector<Node*> collection,Haasje* haasje);
	bool doAlgoritme(std::map<Node*, int> &edgeWeight, std::map<Node *, Node *> &fromTo);
    int calculateTravelCost(Node* current, Node* destinations);
};


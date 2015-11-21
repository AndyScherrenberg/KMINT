#pragma once
#include <map>
#include <list>
#include "Node.h"
#include "Koetje.h"
#include "Haasje.h"

class AlgoRitmeWeek1
{
    void aStar(Beestje* beestje, std::vector<Node*> collection, Node* to);
public:
	AlgoRitmeWeek1();
	~AlgoRitmeWeek1();
    void setNewCawPlace(Node* newPlace, Beestje* koe);
	void doAction(Koetje* koe, std::vector<Node*> collection,Haasje* haasje);
    void goToPlace(Beestje* beestje, std::vector<Node*> collection, Node* destination);
	bool doAlgoritme(std::map<Node*, int> &edgeWeight, std::map<Node *, Node *> &fromTo);
    int calculateTravelCost(Node* current, Node* destinations);
};


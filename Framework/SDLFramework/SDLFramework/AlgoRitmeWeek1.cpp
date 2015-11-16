#include "AlgoRitmeWeek1.h"
#include "Haasje.h"
#include <io.h>
#include <iostream>
AlgoRitmeWeek1::AlgoRitmeWeek1()
{
}


AlgoRitmeWeek1::~AlgoRitmeWeek1()
{
}


void AlgoRitmeWeek1::doAction(Node* currentnode, std::vector<Node*> collection){




	Node* current = currentnode;
	Node* destination;
	std::map<Node*, int> mainmap;
	std::map<Node*, Node*> NodetoNode;
	for (std::vector<Node*>::iterator it = collection.begin(); it != collection.end(); it++){

		mainmap.insert(std::pair<Node*, int>((*it), 1));


		for (std::vector<Edge*>::iterator edge = current->edges.begin(); edge != current->edges.end(); edge++)
		{
			Node* toNode = (*edge)->getNode(current);
			NodetoNode.insert(std::pair<Node*, Node*>(current, toNode));
		}


		if (dynamic_cast<Haasje*>((*it)->getBeestje()))
			destination = (*it);

	}
	std::cout << "Nice";




}
bool AlgoRitmeWeek1::doAlgoritme(std::map<Node*, int> &edgeWeight, std::map<Node *, Node *> &fromTo){
	return false;
}
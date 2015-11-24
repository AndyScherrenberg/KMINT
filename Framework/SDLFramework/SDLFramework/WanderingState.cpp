//
//  WanderingCow.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "WanderingState.hpp"
#include "Node.h"
#include "StateFactory.hpp"
#include <ctime>




void WanderingState::Update(){
	timesInWandering++;
	Node* current = owner->getNode();

	srand(time(0)); // This will ensure a really randomized number by help of time.
	int xRan = rand() % current->edges.size() + 1;

	std::vector<Edge*>::iterator nth = current->edges.begin() + xRan - 1;

	owner->setNode((*nth)->getNode(current));
}

void WanderingState::checkState(){
		if (timesInWandering > owner->getWander()){
   			owner->setState(StateFactory::createNextState(owner->NextState(),owner, nodeMap));
		}
}

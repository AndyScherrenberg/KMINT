//
//  huntState.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "HuntState.hpp"
#include "WanderingState.hpp"
void HuntState::checkState(){


	if (owner->getNode() == owner->getTarget()->getNode())
    {
		owner->CalculateChance(true);
		owner->increaseCaught();
		owner->setState(StateFactory::createNextState(owner->NextState(), owner, nodeMap));
 		owner->getTarget()->CalculateChance(false);
	
		owner->getTarget()->setState(StateFactory::createNextState(owner->getTarget()->getBaseState(), owner->getTarget(), nodeMap));
		nodeMap->resetNodes();

		if (owner->getNode() == owner->getTarget()->getNode()) {
			Node* newTargetNode;
			do{
				int random_index = rand() % nodeMap->getCollection().size();
				newTargetNode = nodeMap->getCollection().at(random_index);
			} while (newTargetNode == owner->getTarget()->getNode());

			owner->getTarget()->setNode(newTargetNode);
		}
    }
}

void HuntState::Update(){
	algoritme->doAction(owner, nodeMap->getCollection(), owner->getTarget());
}
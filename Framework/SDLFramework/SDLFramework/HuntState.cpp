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
		owner->setState(StateFactory::createNextState(owner->NextState(), owner, nodeMap));
		owner->getTarget()->setState(StateFactory::createNextState(1, owner->getTarget(), nodeMap));
		nodeMap->resetNodes();
    }
}

void HuntState::Update(){

	
	algoritme->doAction(owner, nodeMap->getCollection(), owner->getTarget());
    
	/*
	if (nodeMap->getKoe()->getNode() == nodeMap->getHaas()->getNode()) {
        Node* newHaasjeNode;
        do{
			int random_index = rand() % nodeMap->getCollection().size();
			newHaasjeNode = nodeMap->getCollection().at(random_index);
        }
		while (newHaasjeNode == nodeMap->getHaas()->getNode());
        
		nodeMap->getHaas()->setNode(newHaasjeNode);
    }*/


}
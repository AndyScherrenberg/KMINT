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


	if (owner->getNode() == nodeMap->getHaas()->getNode())
    {
		nodeMap->getHaas()->setState(StateFactory::createNextState(1, nodeMap->getHaas(), nodeMap));
		owner->setState(StateFactory::createNextState(owner->NextState(), owner, nodeMap));
		nodeMap->resetNodes();
    }
}

void HuntState::Update(){

	algoritme->doAction(nodeMap->getKoe(), nodeMap->getCollection(), nodeMap->getHaas());
    
	if (nodeMap->getKoe()->getNode() == nodeMap->getHaas()->getNode()) {
        Node* newHaasjeNode;
        do{
			int random_index = rand() % nodeMap->getCollection().size();
			newHaasjeNode = nodeMap->getCollection().at(random_index);
        }
		while (newHaasjeNode == nodeMap->getHaas()->getNode());
        
		nodeMap->getHaas()->setNode(newHaasjeNode);
    }


}
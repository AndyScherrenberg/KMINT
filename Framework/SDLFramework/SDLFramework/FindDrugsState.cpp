//
//  DrugsState.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "FindDrugsState.hpp"
#include <iostream>
FindDrugsState::FindDrugsState(Beestje* beestje, NodeMap* nodemap) : BaseState(beestje, nodemap){

	std::vector<Node*>::iterator dPlace;
	std::vector<Node*> temp = nodemap->getCollection();
	// srand(time(0)); // This will ensure a really randomized number by help of time.
	int xRan = rand() %  nodemap->getCollection().size() + 1;
	dPlace = temp.begin() + xRan - 1;

	while (beestje->getNode() == (*dPlace))
	{
		dPlace =  nodemap->getCollection().begin() + xRan;
	}

	this->drugPlace = (*dPlace);
	this->drugPlace->containsDrugs = true;
}

void FindDrugsState::checkState(){
    if (owner->getNode()->containsDrugs) {
     //   srand(time(0));
        int xRan= rand()% 5;
        if(xRan == 1)
        {
			this->drugPlace->containsDrugs = false;
			owner->setState(StateFactory::createNextState(owner->NextState(), owner, nodeMap));
        }
        else{
            //TODO good drug -> goto hunting
			owner->setState(StateFactory::createNextState(owner->NextState(), owner, nodeMap));
		}
    }
}

void FindDrugsState::Update(){
	nodeMap->getAlgoritme()->goToPlace(owner, nodeMap->getCollection(), drugPlace);    
}
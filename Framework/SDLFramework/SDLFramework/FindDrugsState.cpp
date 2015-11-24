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


	// srand(time(0)); // This will ensure a really randomized number by help of time.
//	int xRan = rand() %  nodemap->getCollection().size() + 1;
//	dPlace = temp.begin() + xRan - 1;

	std::vector<Node*> temp = nodemap->getCollection();
	for (std::vector<Node*>::iterator node = temp.begin(); node != temp.end(); node++)
	{
		if ((*node)->containsDrugs == true)
		{
			this->drugPlace = ((*node));
			this->drugPlace->containsDrugs = true;
			break;
		}
	}

	
}

void FindDrugsState::checkState(){
    if (owner->getNode()->containsDrugs) {
     //   srand(time(0));
        int xRan= rand()% 100;
        if(xRan > 49)
        {
			this->drugPlace->containsDrugs = false;
			owner->setState(StateFactory::createNextState(3, owner, nodeMap));
			owner->currentStateid = 3;
        }
        else{
            //TODO good drug -> goto hunting
			this->drugPlace->containsDrugs = false;
			owner->setState(StateFactory::createNextState(owner->NextState(), owner, nodeMap));
		}
    }
}

void FindDrugsState::Update(){
	nodeMap->getAlgoritme()->goToPlace(owner, nodeMap->getCollection(), drugPlace);    
}
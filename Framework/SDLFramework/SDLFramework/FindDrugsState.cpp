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
	

	
}

void FindDrugsState::checkState(){
    if (owner->getNode()->containsDrugs) {
     //   srand(time(0));

        int xRan= rand()% 100;
        if(xRan > 49)
        {
			this->drugPlace->containsDrugs = false;
			owner->setState(StateFactory::createNextState(owner->getBadDrugState(), owner, nodeMap));
        }
        else{
            //TODO good drug -> goto hunting
			this->drugPlace->containsDrugs = false;
			owner->setState(StateFactory::createNextState(owner->NextState(), owner, nodeMap));
		}
    }
}

void FindDrugsState::Update(){
		std::vector<Node*> temp = this->nodeMap->getCollection();
	for (std::vector<Node*>::iterator node = temp.begin(); node != temp.end(); node++)
	{
		if ((*node)->containsDrugs == true)
		{
			this->drugPlace = ((*node));
			this->drugPlace->containsDrugs = true;
			break;
		}
	}


	nodeMap->getAlgoritme()->goToPlace(owner, nodeMap->getCollection(), drugPlace);    
}
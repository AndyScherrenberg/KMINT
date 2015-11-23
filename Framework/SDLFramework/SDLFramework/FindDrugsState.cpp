//
//  DrugsState.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "FindDrugsState.hpp"
#include "FindWeaponState.hpp"
#include "HuntState.hpp"

FindDrugsState::FindDrugsState(Beestje* beestje, std::vector<Node*> collection, AlgoRitmeWeek1* algoritme) : CowState(beestje){

	std::vector<Node*>::iterator dPlace;

	// srand(time(0)); // This will ensure a really randomized number by help of time.
	int xRan = rand() % collection.size() + 1;
	dPlace = collection.begin() + xRan - 1;

	if (beestje->getNode() == (*dPlace))
	{
		dPlace = collection.begin() + xRan;
	}

	this->drugPlace = (*dPlace);
	this->drugPlace->containsDrugs = true;
	this->algoritme = algoritme;
	this->collection = collection;


}
void FindDrugsState::checkState(){
    if (owner->getNode()->containsDrugs) {
     //   srand(time(0));
        int xRan= rand()% 5;
        if(xRan == 1)
        {
			this->drugPlace->containsDrugs = false;
			owner->setState(new FindWeaponState(owner,collection, algoritme));
        }
        else{
            //TODO good drug -> goto hunting
			//owner->setState(new HuntState(owner, collection, algoritme));       
		}
    }
}

void FindDrugsState::Update(){
	algoritme->goToPlace(owner, collection, drugPlace);

    //TODO zoek naar een drug node
    
}
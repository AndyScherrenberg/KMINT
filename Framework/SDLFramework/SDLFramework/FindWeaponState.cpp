//
//  FindWeaponState.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "FindWeaponState.hpp"
#include <iostream>
#include "HuntState.hpp"

FindWeaponState::FindWeaponState(Beestje* beestje, NodeMap* nodemap) : BaseState(beestje, nodemap){


	std::vector<Node*>::iterator wplace;
	std::vector<Node*> temp = nodemap->getCollection();
	// srand(time(0)); // This will ensure a really randomized number by help of time.
	int xRan = rand() % temp.size() + 1;
	wplace = temp.begin() + xRan - 1;

	if (beestje->getNode() == (*wplace))
	{
		wplace = nodemap->getCollection().begin() + xRan;
	}

	this->weaponPlace = (*wplace);
	this->weaponPlace->containsWeapon = true;
}


void FindWeaponState::checkState(){
    if(owner->getNode() == this->weaponPlace)
    {
		owner->GiveWeapon(); 
		this->weaponPlace->containsWeapon = false;
		owner->setState(StateFactory::createNextState(owner->NextState(), owner, nodeMap));
	}
}

void FindWeaponState::Update(){
    algoritme->goToPlace(owner, collection, weaponPlace);
}
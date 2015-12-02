//
//  FindWeaponState.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "FindBootState.hpp"
#include <iostream>

FindBootState::FindBootState(Beestje* beestje, NodeMap* nodemap) : BaseState(beestje, nodemap){

    this->collection = nodemap->getCollection();
	std::vector<Node*> temp = nodemap->getCollection();
	for (std::vector<Node*>::iterator node = temp.begin(); node != temp.end(); node++)
	{
		if ((*node)->containsWeapon == true)
		{
			this->weaponPlace = ((*node));
			this->weaponPlace->containsWeapon = true;
			break;
		}


	}
	
}


void FindBootState::checkState(){
    if(owner->getNode() == this->weaponPlace)
    {
		owner->SetBoots(); 
		this->weaponPlace->containsWeapon = false;
		owner->setState(StateFactory::createNextState(owner->NextState(), owner, nodeMap));
	}
}

void FindBootState::Update(){
    algoritme->goToPlace(owner, collection, weaponPlace);
}
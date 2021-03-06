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



	CreateWeapon();
	CheckWeapon();
}


void FindBootState::checkState(){

	CheckWeapon();
    if(owner->getNode() == this->weaponPlace)
    {
		owner->SetBoots(); 
		this->weaponPlace->containsWeapon = false;
		this->weaponPlace = nullptr;
		CreateWeapon();
		owner->setState(StateFactory::createNextState(owner->NextState(), owner, nodeMap));
	
	}
}

void FindBootState::Update(){
	CheckWeapon();
    algoritme->goToPlace(owner, collection, weaponPlace);
}

void FindBootState::CheckWeapon()
{
	std::vector<Node*> temp = nodeMap->getCollection();
	for (std::vector<Node*>::iterator node = temp.begin(); node != temp.end(); node++)
	{
		if ((*node)->containsWeapon == true)
		{
			this->weaponPlace = ((*node));
			break;
		}
	}
}

void FindBootState::CreateWeapon(){
	std::vector<Node*>::iterator wplace;

	std::vector<Node*> temp = nodeMap->getCollection();

	srand(time(NULL));

	/* generate secret number between 1 and 10: */
	// int iSecret =



	bool placeWeapon = true;

	for (wplace = temp.begin(); wplace != temp.end(); wplace++){
		if ((*wplace)->containsWeapon){
			placeWeapon = false;
			break;
		}
	}

	int i = rand() % 6 + 1;

    wplace = temp.begin() + i;
	while (placeWeapon)
	{
		if ((*wplace)->getBeestje() == nullptr && (*wplace)->containsDrugs == false)
		{
			(*wplace)->containsWeapon = true;
			(*wplace)->setTexture();
			placeWeapon = false;
		}
		else{
			int j = rand() % 6 + 1;
			wplace = temp.begin() + j;
		}
	}
}
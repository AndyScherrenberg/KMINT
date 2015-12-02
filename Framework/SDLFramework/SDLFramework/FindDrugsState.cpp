//
//  DrugsState.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "FindDrugsState.hpp"
#include <iostream>
#include "Node.h"
FindDrugsState::FindDrugsState(Beestje* beestje, NodeMap* nodemap) : BaseState(beestje, nodemap){	
	CreateDrugs();
}

void FindDrugsState::checkState(){
	
    CheckDrugs();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 100);
	int random = dis(gen) - 1;
	int state = owner->getBadDrugState();
	if (random < 50)
		state = owner->NextState();

	if (owner->getNode()->containsDrugs) {
		
		this->drugPlace->containsDrugs = false;
		this->drugPlace = nullptr;
		CreateDrugs();
		owner->setState(StateFactory::createNextState(state, owner, nodeMap));
	
	}
}

void FindDrugsState::Update(){
	CheckDrugs();
	nodeMap->getAlgoritme()->goToPlace(owner, nodeMap->getCollection(), drugPlace);
}

void FindDrugsState::CheckDrugs()
{
	std::vector<Node*> temp = this->nodeMap->getCollection();
	for (std::vector<Node*>::iterator node = temp.begin(); node != temp.end(); node++)
	{
		if ((*node)->containsDrugs == true)
		{
			this->drugPlace = ((*node));
			break;
		}
	}
}
void FindDrugsState::CreateDrugs(){
	std::vector<Node*>::iterator dplace;
	std::vector<Node*> temp = nodeMap->getCollection();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, int(temp.size()));

	bool placeDrugs = true;

	int drugsAmount = 0;
	for (dplace = temp.begin(); dplace != temp.end(); dplace++){
		if ((*dplace)->containsDrugs){
			drugsAmount++;
		}
		if (drugsAmount == 1)
			break;
	}

	if (drugsAmount == 1)
		placeDrugs = false;
    
    int i = dis(gen) - 1;

	dplace = temp.begin() + i;
	//	int i = 0;
	while (placeDrugs)
	{
		if ((*dplace)->getBeestje() == nullptr && (*dplace)->containsWeapon == false && (*dplace)->containsDrugs == false)
		{
			(*dplace)->containsDrugs = true;
			(*dplace)->setTexture();
			placeDrugs = false;

			drugsAmount++;

			if (drugsAmount == 1)
				placeDrugs = false;

		}
		else{
            int j = dis(gen) - 1;
			dplace = temp.begin() + j;
		}
	}

	CheckDrugs();
}
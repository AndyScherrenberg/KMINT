//
//  WanderingCow.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "WanderingCow.hpp"
#include "Node.h"
#include "StateFactory.hpp"
#include "FindDrugsState.hpp"
#include <ctime>


WanderingCow::WanderingCow(Beestje* beestje, std::vector<Node*> collection, AlgoRitmeWeek1* algoritme) : CowState(beestje){

	this->algoritme = algoritme;
	this->collection = collection;


}

void WanderingCow::Update(){
    timesInWandering++;
    
    Node* current = owner->getNode();
        
        srand(time(0)); // This will ensure a really randomized number by help of time.
        int xRan=rand()%current->edges.size()+1;
        
        std::vector<Edge*>::iterator nth = current->edges.begin() + xRan -1;
        
        owner->setNode((*nth)->getNode(current));
}

void WanderingCow::checkState(){
	if (dynamic_cast<Koetje*>(owner))
	{

		if (timesInWandering > 3){
 			owner->setState(new FindDrugsState(owner, this->collection, this->algoritme));
		}
	}
}

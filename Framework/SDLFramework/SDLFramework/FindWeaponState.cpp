//
//  FindWeaponState.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "FindWeaponState.hpp"
#include <iostream>

FindWeaponState::FindWeaponState(Beestje* beestje,std::vector<Node*> collection,AlgoRitmeWeek1* algoritme): CowState(beestje){
    
    std::vector<Node*>::iterator wplace;

  // srand(time(0)); // This will ensure a really randomized number by help of time.
    int xRan=rand()%collection.size()+1;
    wplace = collection.begin() + xRan -1;
    
    if(beestje->getNode() == (*wplace))
    {
        wplace = collection.begin() + xRan;
    }

    this->weaponPlace = (*wplace);
    this->algoritme = algoritme;
    this->collection = collection;
}

void FindWeaponState::checkState(){
    if(owner->getNode() == this->weaponPlace)
    {
        std::cout << "weapon found" << std::endl;

        //TODO: Haas is dood en spel begint opnieuw.
    }
}

void FindWeaponState::Update(){
    algoritme->goToPlace(owner, collection, weaponPlace);
}
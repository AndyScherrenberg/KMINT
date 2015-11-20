//
//  DrugsState.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "FindDrugsState.hpp"

void FindDrugsState::checkState(){
    if (owner->getNode()->containsDrugs) {
        srand(time(0));
        int xRan= rand()% 5;
        if(xRan == 1)
        {
            //TODO bad drug -> goto find weapon
        }
        else{
            //TODO good drug -> goto hunting
        }
    }
}

void FindDrugsState::Update(){
    //TODO zoek naar een drug node
    
}
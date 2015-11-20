//
//  huntState.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "HuntState.hpp"

void HuntState::checkState(){
    
}

void HuntState::Update(){
    // TODO Start A*
    algoritme->doAction(koe, collection, haasje);
    
    if (koe->getNode() == haasje->getNode()) {
        // staan op elkaar
        
        //TODO Koe naar WANDERING state
        
        // Geef haas nieuwe plek
        Node* newHaasjeNode;
        do{
            int random_index = rand() % collection.size();
            newHaasjeNode = collection.at(random_index);
        }
        while(newHaasjeNode == haasje->getNode());
        
        haasje->setNode(newHaasjeNode);
    }
}
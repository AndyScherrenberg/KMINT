//
//  CowState.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "CowState.hpp"

CowState::CowState(Beestje * beestje){
    this->owner = beestje;
}
CowState::~CowState(){
    
}

void CowState::Update(){
    
}

void CowState::checkState(){
    
}

const char* CowState::stateToText(){
    return "not implemented";
}
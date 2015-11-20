//
//  StateFactory.hpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#ifndef StateFactory_hpp
#define StateFactory_hpp

#include "CowState.hpp"
#include "WanderingCow.hpp"
#include <stdio.h>

class Beestje;

class StateFactory{
   
public:
    StateFactory(){};
    CowState* createNextCowState(int id,Beestje* beestje);
};
#endif /* StateFactory_hpp */

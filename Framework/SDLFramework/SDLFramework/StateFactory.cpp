//
//  StateFactory.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "StateFactory.hpp"


CowState* StateFactory::createNextCowState(int id,Beestje* beestje){
    if(id == 0){
        return new WanderingCow(beestje);
    }
    else
    {
        return new WanderingCow(beestje);
    }
}
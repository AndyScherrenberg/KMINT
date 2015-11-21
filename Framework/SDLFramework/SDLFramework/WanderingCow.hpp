//
//  WanderingCow.hpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#ifndef WanderingCow_hpp
#define WanderingCow_hpp

#include <stdio.h>
#include "CowState.hpp"

class WanderingCow: public CowState
{
    int timesInWandering = 0;
public:
    WanderingCow(Beestje* beestje): CowState(beestje){};
    ~WanderingCow();
    const char* stateToText() override {return "Wandering";};
    void Update() override;
    void checkState() override;
};


#endif /* WanderingCow_hpp */

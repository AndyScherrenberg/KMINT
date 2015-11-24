//
//  WanderingCow.hpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#ifndef WanderingState_hpp
#define WanderingState_hpp

#include <stdio.h>
#include "BaseState.hpp"
#include "AlgoRitmeWeek1.h"
class WanderingState : public BaseState
{
    int timesInWandering = 0;
	std::vector<Node*> collection;
	AlgoRitmeWeek1* algoritme;
public:
	WanderingState(Beestje* beestje, NodeMap* nodemap) : BaseState(beestje,  nodemap){};
	~WanderingState();
    const char* stateToText() override {return "Wandering";};
    void Update() override;
    void checkState() override;
};


#endif /* WanderingCow_hpp */

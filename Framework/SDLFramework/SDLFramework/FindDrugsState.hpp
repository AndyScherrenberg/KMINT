//
//  DrugsState.hpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#ifndef DrugsState_hpp
#define DrugsState_hpp

#include <stdio.h>
#include "BaseState.hpp"
#include "AlgoRitmeWeek1.h"

class FindDrugsState : public BaseState
{
	Node* drugPlace;
	AlgoRitmeWeek1* algoritme;
	std::vector<Node*> collection;
public:
	FindDrugsState(Beestje* beestje, NodeMap* nodemap);

    ~FindDrugsState();
    const char* stateToText() override {return "Drug Finding";};
    void Update() override;
    void checkState() override;
};
#endif

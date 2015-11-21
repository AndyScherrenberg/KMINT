//
//  huntState.hpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#ifndef huntState_hpp
#define huntState_hpp

#include <stdio.h>
#include "AlgoRitmeWeek1.h"
#include "Koetje.h"
#include "Haasje.h"

class HuntState: public CowState
{
    AlgoRitmeWeek1* algoritme;
    Koetje* koe;
    std::vector<Node*> collection;
    Haasje* haasje;
public:
    HuntState(Beestje* owner,Koetje* koe, std::vector<Node*> collection,Haasje* haasje): CowState(owner){algoritme = new AlgoRitmeWeek1();};
    ~HuntState();
    const char* stateToText() override {return "Hunting";};
    void Update() override;
    void checkState() override;
};

#endif /* huntState_hpp */

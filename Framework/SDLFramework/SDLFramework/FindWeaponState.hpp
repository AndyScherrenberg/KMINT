//
//  FindWeaponState.hpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#ifndef FindWeaponState_hpp
#define FindWeaponState_hpp

#include <stdio.h>
#include "CowState.hpp"
#include "AlgoRitmeWeek1.h"




class FindWeaponState: public CowState
{
    Node* weaponPlace;
    AlgoRitmeWeek1* algoritme;
    std::vector<Node*> collection;
public:
    FindWeaponState(Beestje* beestje,std::vector<Node*> collection, AlgoRitmeWeek1* algoritme);
    ~FindWeaponState();
    const char* stateToText() override {return "FindWeapon";};
    void Update() override;
    void checkState() override;
};

#endif /* FindWeaponState_hpp */

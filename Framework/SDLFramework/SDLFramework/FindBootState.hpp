//
//  FindWeaponState.hpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#ifndef FindBootState_hpp
#define FindBootState_hpp

#include <stdio.h>
#include "BaseState.hpp"
#include "AlgoRitmeWeek1.h"

class FindBootState : public BaseState
{
    Node* weaponPlace;
    AlgoRitmeWeek1* algoritme;
    std::vector<Node*> collection;

	std::random_device rd;
	std::default_random_engine gen;
	std::uniform_int_distribution<int> dis;


public:
	FindBootState(Beestje* beestje, NodeMap* nodemap);
	~FindBootState();
    const char* stateToText() override {return "Find Boots";};
    void Update() override;
    void checkState() override;
	void CreateWeapon();
	void CheckWeapon();
};

#endif /* FindWeaponState_hpp */

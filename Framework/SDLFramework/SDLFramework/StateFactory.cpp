//
//  StateFactory.cpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "StateFactory.hpp"
#include "WanderingState.hpp"
#include "FindDrugsState.hpp"
#include "FindWeaponState.hpp"
#include "HuntState.hpp"
#include "SleepState.h"


BaseState* StateFactory::createNextState(int id, Beestje* beestje, NodeMap* nodeMap){


	switch (id)
	{
	case 1:
		return new WanderingState(beestje, nodeMap);
		break;
	case 2:
		return new FindDrugsState(beestje, nodeMap);
		break;
	case 3:
		return new FindWeaponState(beestje, nodeMap);
		break;
	case 4:
		return new HuntState(beestje, nodeMap);
		break;
	case 5:
		return new SleepState(beestje, nodeMap);
		break;
	default:
		return new WanderingState(beestje, nodeMap);
		break;
	}


	return nullptr;
   
	
}
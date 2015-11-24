//
//  StateFactory.hpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

//TODO Stateverwijs naar state;

#ifndef StateFactory_hpp
#define StateFactory_hpp

#include "BaseState.hpp"
#include "NodeMap.h"
#include <stdio.h>

class Beestje;
class NodeMap;
static class StateFactory{
   
public:
    StateFactory(){};
	static BaseState* createNextState(int id, Beestje* beestje, NodeMap* nodemap);
};
#endif /* StateFactory_hpp */

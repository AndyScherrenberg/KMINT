//
//  CowState.hpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#ifndef BaseState_hpp
#define BaseState_hpp


#include <stdio.h>
#include "Beestje.h"
#include "NodeMap.h"
#include <time.h>       /* time */

class NodeMap;
class Beestje;

class BaseState
{

protected:
    Beestje* owner;
	NodeMap* nodeMap;

public:
	BaseState(Beestje* beestje, NodeMap* nodemap)
	{
		this->owner = beestje;
		this->nodeMap = nodemap;
	
	}
	~BaseState();
    virtual void Update();
    virtual void checkState();
    virtual const char* stateToText();
};

#endif /* CowState_hpp */
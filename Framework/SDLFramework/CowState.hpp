//
//  CowState.hpp
//  KMINT
//
//  Created by Bryan Sijs on 20-11-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#ifndef CowState_hpp
#define CowState_hpp


#include <stdio.h>
#include "Beestje.h"



class Beestje;
class CowState
{
protected:
    Beestje* owner;
public:
    CowState(Beestje* beestje);
    ~CowState();
    virtual void Update();
    virtual void checkState();
    const char* stateToText();
};


#endif /* CowState_hpp */

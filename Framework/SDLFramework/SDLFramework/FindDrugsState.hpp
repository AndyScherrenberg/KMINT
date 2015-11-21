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
#include "CowState.hpp"

class FindDrugsState: public CowState
{
public:
    FindDrugsState(Beestje* beestje): CowState(beestje){};
    ~FindDrugsState();
    const char* stateToText() override {return "Drug Finding";};
    void Update() override;
    void checkState() override;
};
#endif /* DrugsState_hpp */

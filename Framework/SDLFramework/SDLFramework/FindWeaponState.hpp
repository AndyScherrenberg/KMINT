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

class FindWeaponState: public CowState
{
public:
    FindWeaponState(Beestje* beestje): CowState(beestje){};
    ~FindWeaponState();
    const char* stateToText(){return "FindWeapon";};
    void Update() override;
    void checkState() override;
};

#endif /* FindWeaponState_hpp */

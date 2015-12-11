//
//  GameWorld.hpp
//  KMINT
//
//  Created by Bryan Sijs on 11-12-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#ifndef GameWorld_hpp
#define GameWorld_hpp

#include <stdio.h>
#include "MovingEntity.hpp"

class GameWorld{
    
public:
    GameWorld();
    ~GameWorld();
    void UpdateEntity(MovingEntity* entity);
};
#endif /* GameWorld_hpp */

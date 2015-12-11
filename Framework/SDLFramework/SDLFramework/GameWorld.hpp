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
#include "CowEntity.h"

class GameWorld{
    std::vector<CowEntity*> cowList;
    
public:
    GameWorld();
    ~GameWorld();
    void UpdateEntity(MovingEntity* entity);
    void setCowList(std::vector<CowEntity*> cowList){this->cowList = cowList;};
    std::vector<CowEntity*> getCowList(){return this->cowList;};
    void addCowToCowList(CowEntity* cow){this->cowList.push_back(cow);};
};
#endif /* GameWorld_hpp */

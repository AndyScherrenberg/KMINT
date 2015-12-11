//
//  GameWorld.cpp
//  KMINT
//
//  Created by Bryan Sijs on 11-12-15.
//  Copyright © 2015 Bryan Sijs. All rights reserved.
//

#include "GameWorld.hpp"
#include "SDL.h"

GameWorld::GameWorld(){
    
}
GameWorld::~GameWorld(){
    
}

void GameWorld::UpdateEntity(MovingEntity* entity){
    
    float xCor = entity->getPostion().getX();
    float yCor = entity->getPostion().getY();
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);    
    int screenX = 800;
    int screenY = 600;
    
    if(xCor > screenX + 50){
        //Rechts uit beeld
        entity->setPosition(Vector2D {-50,yCor});
    }
    if(xCor < -50){
        //Links uit beeld
        entity->setPosition(Vector2D {static_cast<float>(screenX+50),yCor});
    }
    if(yCor > screenY + 50 ){
        //Onder uit beeld
        entity->setPosition(Vector2D {xCor,-50});
    }
    if(yCor < -50){
        //Boven uit beeld
        entity->setPosition(Vector2D {xCor,static_cast<float>(screenY +50)});
    }
}
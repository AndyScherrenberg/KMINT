#pragma once
#include "Beestje.h"
#include "BaseState.hpp"
#include <random>
#include <iostream>

class Haasje : public Beestje
{
public:
	Haasje();
	~Haasje();
	virtual void Draw() override;
	virtual void Update(float deltaTime) override;

	virtual int NextState(){

        //Random r
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 50);
		int r = dis(gen);

		std::map<int, int>::iterator it;

		int newState = getBaseState();

		for (it = StateMap.begin(); it != StateMap.end(); it++)
		{

			if (it->first == getCurrentStateId())
			{
				if (it->second == wanderState)
				{
					if (r < wanderChance || (wanderChancePercentage < 10 && r >25))
					{
						newState = it->second;
                        break; 
					}
				}
				else if (it->second == sleepState){
					if (r < sleepChance || (sleepChancePercentage < 10 && r >1))
					{
						newState = it->second;
                        break;
					}
				}

				else if (it->second == findState)
				{
					if ( r < findChance || (findChancePercentage < 10 && r >25))
					{
						newState = it->second;
                        break;
					}
				}
				else{
	
					this->setCurrentStateId(it->second);
					return it->second;
				}
			}
		}

		this->setCurrentStateId(newState);
		return newState;
	}



	virtual void CalculateChance(bool positive)
	{
        //Wander
		if (getCurrentStateId() == 1)
		{
			if (positive)
			{
				wanderChance += 50;
				findChance -= 5;
				sleepChance -= 5;
			}
			else
			{
				wanderChance -= 10;
				findChance += 40;
				sleepChance += 10;
			}
		}
        
        //Sleep
		if (getCurrentStateId() == 5)
		{
			if (positive)
			{
				sleepChance += 1;
				//findChance -= 5;
				//wanderChance -= 5;
			}
			else
			{
				sleepChance -= 80;
				wanderChance += 80;
				findChance += 80;
			}
		}
        
        //FindDrug
		if (getCurrentStateId() == 2)
		{
			if (positive)
			{
				findChance += 60;
				sleepChance -= 20;
				wanderChance -= 5;
			}
			else
			{
				findChance -= 25;
				sleepChance += 1;
				wanderChance += 10;
			}
		}
        
        //Hunt
        if (getCurrentStateId() == 4)
        {
            if (positive)
            {
                huntChance += 80;
                findChance -= 5;
                sleepChance -= 20;
                wanderChance -= 5;
            }
            else
            {
                huntChance-= 10;
                findChance += 25;
                sleepChance += 1;
                wanderChance += 10;
            }
        }
    }

	int sleepChance = 25;
	int wanderChance = 25;
	int findChance = 25;
    int huntChance = 25;
    
    int sleepChancePercentage = 25;
    int wanderChancePercentage = 25;
    int findChancePercentage = 25;
    int huntChancePercentage = 25;
    
    void calculateChancePercentage();

    int getSleepChancePercentage();
    int getWanderChancePercentage();
    int getFindChancePercentage();
    int getHuntChancePercentage();

	int wanderState = 1;
	int sleepState = 5;
	int findState = 2;
    int huntState = 4;
};


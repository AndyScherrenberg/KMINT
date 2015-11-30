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
					if (wanderChance > r)
					{
						newState = it->second;
                        break; 
					}
				}
				else if (it->second == sleepState){
					if (sleepChance > r)
					{
						newState = it->second;
                        break;
					}
				}

				else if (it->second == findState)
				{
 					if (findChance > r)
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
				wanderChance += 10;
				findChance -= 5;
				sleepChance -= 5;
			}
			else
			{
				wanderChance -= 5;
				findChance += 10;
				sleepChance += 5;
			}
		}
        
        //Sleep
		if (getCurrentStateId() == 5)
		{
			if (positive)
			{
				sleepChance += 10;
				findChance -= 5;
				wanderChance -= 5;
			}
			else
			{
				sleepChance -= 5;
				wanderChance += 10;
				findChance += 5;
			}
		}
        
        //FindDrug
		if (getCurrentStateId() == 2)
		{
			if (positive)
			{
				findChance += 15;
				sleepChance -= 5;
				wanderChance -= 5;
			}
			else
			{
				findChance -= 5;
				sleepChance += 10;
				wanderChance += 5;
			}
		}

    }

	int sleepChance = 33;
	int wanderChance = 33;
	int findChance = 33;
    
    int sleepChancePercentage = 33;
    int wanderChancePercentage = 33;
    int findChancePercentage = 33;
    
    int getSleepChancePercentage();
    int getWanderChancePercentage();
    int getFindChancePercentage();
    void calculateChancePercentage();

	int wanderState = 1;
	int sleepState = 5;
	int findState = 2;
};


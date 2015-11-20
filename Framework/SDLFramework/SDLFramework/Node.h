#pragma once
#include "Edge.h"
#include "IGameObject.h"
#include <vector>
#include <string>
#include "Beestje.h"

class Edge;
class Beestje;

class Node : public IGameObject
{
public:
	Node(std::string ch, int loc_x, int loc_y){
		this->ch = ch;
		this->x = loc_x;
		this->y = loc_y;

		this->h = 25;
		this->w = 25;

	}
	~Node();
	Node();

	virtual void Draw() override;
	virtual void Update(float deltaTime) override;

	void addEgde(Edge* edge)
	{
		this->edges.push_back(edge);
	}
    
    bool operator < (const Node* str) const
    {
        return (pixelsToDestination < str->pixelsToDestination);
    }
    
    bool operator > (const Node* str) const
    {
        return (pixelsToDestination > str->pixelsToDestination);
    }

	std::vector<Edge*> edges;
	int weight;
	int x;
	int y;
	int h; // hoogte blokje
	int w; //breedte blokje
	std::string ch;
    
    //Algortime
    int travelCost = 0;
    Node* traveledFrom;
    int pixelsToDestination;
    
    // States
    bool containsDrugs = false;
    bool containsWeapon = false;

	void setBeestje(Beestje* beestje){ this->beestje = beestje; };
	Beestje* getBeestje(){ return this->beestje; };
    
private:
        Beestje* beestje;
};


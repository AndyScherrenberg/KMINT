#pragma once
#include "Node.h"
#include "Edge.h"
#include "Koetje.h"
#include "Haasje.h"
#include "StateFactory.hpp"
#include "AlgoRitmeWeek1.h"

class BaseState;
class Koetje;
class Haasje;
class AlgoRitmeWeek1;
class NodeMap
{
private:
	Koetje* koe;
	Haasje* haas;
	AlgoRitmeWeek1* aStar;
	std::vector<Node*> nodeList;
public:


	void resetNodes();
	NodeMap(FWApplication* application);
	~NodeMap();
	void Update();
	FWApplication* application;
	Koetje* getKoe(){ return koe; }
	Haasje* getHaas(){ return haas; }
	std::vector<Node*> getCollection(){ return nodeList; }
	void setStates();

	void setKoe(Koetje* koe){
		this->koe = koe;
	}



	void setHaas(Haasje* haas){
		this->haas = haas;
	}

	AlgoRitmeWeek1* getAlgoritme()
	{
		return aStar;
	}
};


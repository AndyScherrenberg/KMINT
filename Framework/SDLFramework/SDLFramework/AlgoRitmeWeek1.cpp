
#include "AlgoRitmeWeek1.h"
#include "Haasje.h"
#include "Koetje.h"
#ifdef __APPLE__
#include <sys/uio.h>
#else
#include <sys/io.h>
#endif
#include <iostream>
#include <queue>
AlgoRitmeWeek1::AlgoRitmeWeek1()
{
}


AlgoRitmeWeek1::~AlgoRitmeWeek1()
{
}

void AlgoRitmeWeek1::doAction(Koetje* koe, std::vector<Node*> collection, Node* destination){

	Node* current = koe->getNode();
	std::vector<Node*> closedList;
    std::vector<Node*> openList;
    
    //INIT: Zet de huidige node in de closedList en de buren in de openList
    closedList.push_back(current);
    
    for (std::vector<Edge*>::iterator edge = current->edges.begin(); edge != current->edges.end(); edge++)
    {
        Node* toNode = (*edge)->getNode(current);
        toNode->travelCost = (*edge)->getWeight();//TODO Add Distance
        toNode->traveledFrom = current;
        openList.push_back(toNode);
        // Zet de Node met de laagste travelCost vooraan
        std::sort(openList.begin(), openList.end());
    }
    
    // Start Algortime
    while (!openList.empty()) {
        // Get current Node
        Node* current = openList.front();
        
        if(current == destination)
        {
            Node* finder = destination;
            //found
            while(finder->traveledFrom != koe->getNode()){
                finder = finder->traveledFrom;
            }
            setNewCawPlace(finder, koe);

            break;
        }
        
        // Add current node to closedList
        
        closedList.push_back(current);
        
        //Kijk naar de buren en voeg ze toe aan de openList
        for (std::vector<Edge*>::iterator edge = current->edges.begin(); edge != current->edges.end(); edge++)
        {
            Node* toNode = (*edge)->getNode(current);
            if(std::find(closedList.begin(), closedList.end(), toNode) == closedList.end()) {
                /* closedList not contains current */
                int newTravelCost = current->travelCost + (*edge)->getWeight();//TODO Add Distance
                if (toNode->travelCost > newTravelCost || toNode->travelCost == -1) {
                    //update travelCost
                    toNode->travelCost = newTravelCost;
                    toNode->traveledFrom = current;
                }
                
                openList.push_back(toNode);
                // Zet de Node met de laagste travelCost vooraan
                std::sort(openList.begin(), openList.end());
            }
        }
        // Haal current uit de openList
        openList.erase(openList.begin());
    }
}

void AlgoRitmeWeek1::setNewCawPlace(Node* newPlace, Koetje* koe){
    koe->setNode(newPlace);
}

bool AlgoRitmeWeek1::doAlgoritme(std::map<Node*, int> &edgeWeight, std::map<Node *, Node *> &fromTo){
	return false;
}

#include "AlgoRitmeWeek1.h"
#include "Haasje.h"
#include "Koetje.h"
#ifdef __APPLE__
#include <sys/uio.h>
#else
#include <io.h>
#endif
#include <iostream>
#include <queue>
AlgoRitmeWeek1::AlgoRitmeWeek1()
{
}


AlgoRitmeWeek1::~AlgoRitmeWeek1()
{
}


int AlgoRitmeWeek1::calculateTravelCost(Node* current, Node* destination){
    
    int x = std::abs(destination->x - current->x);
    int y = std::abs(destination->y - current->y);
    
    int pixelDifference = sqrt((x*x) + (y*y));
    
    return pixelDifference;
}

void AlgoRitmeWeek1::aStar(Beestje* beestje, std::vector<Node*> collection, Node* destination)
{
    std::vector<Node*> edgeNodes;
    Node* current = beestje->getNode();
    std::vector<Node*> closedList;
    std::vector<Node*> openList;
    
    
    //reset all nodes
    for (std::vector<Node*>::iterator node = collection.begin(); node != collection.end(); node++)
    {
        (*node)->travelCost = 0;
        (*node)->traveledFrom = nullptr;
    }
    
    //INIT: Zet de huidige node in de closedList en de buren in de openList
    closedList.push_back(current);
    
    for (std::vector<Edge*>::iterator edge = current->edges.begin(); edge != current->edges.end(); edge++)
    {
        Node* toNode = (*edge)->getNode(current);
        toNode->travelCost = current->travelCost + (*edge)->getWeight();
        toNode->pixelsToDestination = calculateTravelCost(current, toNode);
        toNode->traveledFrom = current;
        
        edgeNodes.push_back(toNode);
        // Zet de Node met de laagste travelCost vooraan
        //std::sort(openList.begin(), openList.end());
#ifdef __APPLE__
        std::stable_sort(std::begin(edgeNodes),std::end(edgeNodes),[](const Node* p1, const Node* p2) { return (p1->pixelsToDestination + p1->travelCost) > (p2-> pixelsToDestination + p2->pixelsToDestination); });
#endif
    }
    //openList.insert(edgeNodes.begin(), edgeNodes.end(), openList.end());
    openList.insert(openList.end(), edgeNodes.begin(), edgeNodes.end());
    edgeNodes.clear();
    
    // Start Algortime
    while (!openList.empty()) {
        // Get current Node
        Node* current = openList.front();
        // Add current node to closedList
        
        closedList.push_back(current);
        
        // Haal current uit de openList
        openList.erase(openList.begin());
        std::sort(openList.begin(), openList.end());
        
        
        if(current == destination)
        {
            Node* finder = destination;
            if (finder->traveledFrom == beestje->getNode()) {
                // 1 stap voor de haas
                setNewCawPlace(destination, beestje);
                //                Node* newHaasjeNode;
                //                do{
                //                    int random_index = rand() % collection.size();
                //                    newHaasjeNode = collection.at(random_index);
                //                }
                //                while(newHaasjeNode == haasje->getNode());
                //
                //                haasje->setNode(newHaasjeNode);
                break;
            }
            //found
            while(finder->traveledFrom != beestje->getNode()){
                finder = finder->traveledFrom;
            }
            setNewCawPlace(finder, beestje);
            
            
            break;
        }
        
        
        //Kijk naar de buren en voeg ze toe aan de openList
        for (std::vector<Edge*>::iterator edge = current->edges.begin(); edge != current->edges.end(); edge++)
        {
            Node* toNode = (*edge)->getNode(current);
            
            if(std::find(closedList.begin(), closedList.end(), toNode) == closedList.end()) {
                /* closedList not contains current */
                int newTravelCost = current->travelCost + (*edge)->getWeight();
                
                if (toNode->travelCost > newTravelCost || toNode->travelCost == 0)
                {
                    //update travelCost
                    toNode->travelCost = newTravelCost;
                    toNode->pixelsToDestination = calculateTravelCost(current, destination);
                    toNode->traveledFrom = current;
                }
                
                if ( std::find(openList.begin(), openList.end(), toNode) == openList.end()){
                    edgeNodes.push_back(toNode);
                }
                
                // Zet de Node met de laagste travelCost vooraan
                //std::sort(openList.begin(), openList.end());
#ifdef __APPLE__
                std::stable_sort(std::begin(edgeNodes),std::end(edgeNodes),[](const Node* p1, const Node* p2) { return (p1->pixelsToDestination + p1->travelCost) > (p2->pixelsToDestination + p2->pixelsToDestination); });
#endif
            }
        }
        openList.insert(openList.end(), edgeNodes.begin(), edgeNodes.end());
        edgeNodes.clear();
    }
}

void AlgoRitmeWeek1::doAction(Koetje* koe, std::vector<Node*> collection, Haasje* haasje){
    aStar(koe, collection, haasje->getNode());
}

void AlgoRitmeWeek1::goToPlace(Beestje* beestje, std::vector<Node*> collection, Node* destination){
    aStar(beestje, collection, destination);
}

void AlgoRitmeWeek1::setNewCawPlace(Node* newPlace, Beestje* koe){
    koe->setNode(newPlace);
}

bool AlgoRitmeWeek1::doAlgoritme(std::map<Node*, int> &edgeWeight, std::map<Node *, Node *> &fromTo){
	return false;
}
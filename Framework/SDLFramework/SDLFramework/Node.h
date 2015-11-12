#pragma once
#include "Edge.h"
#include <vector>

class Edge;

class Node
{
public:
	Node(char ch, int loc_x, int loc_y){
		this->ch = ch;
		this->x = loc_x;
		this->w = loc_y;


		this->h = 10;
		this->w = 10;
				
	}
	~Node();
	Node();

	void draw()
	{

	}
	std::vector<Edge*> edges;
	int weight;
	int x;
	int y;
		int h;
	int w;
	char ch;
	

};


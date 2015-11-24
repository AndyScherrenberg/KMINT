#include "NodeMap.h"
#include "WanderingState.hpp"
void NodeMap::Update()
{
	this->getKoe()->Update(1.00);
	this->getHaas()->Update(1.00);
}

NodeMap::NodeMap(FWApplication* application)
{
	this->application = application;


	Node* a = new Node("A", 100, 200);
	Node* b = new Node("B", 200, 100);
	Node* c = new Node("C", 370, 100);
	Node* d = new Node("D", 300, 180);
	Node* e = new Node("E", 450, 200);
	Node* f = new Node("F", 200, 300);
	Node* g = new Node("G", 330, 300);

	this->nodeList.push_back(a);
	this->nodeList.push_back(b);
	this->nodeList.push_back(c);
	this->nodeList.push_back(d);
	this->nodeList.push_back(e);
	this->nodeList.push_back(f);
	nodeList.push_back(g);

	Edge* ab = new Edge(a, b, 5000000);
	Edge* bc = new Edge(b, c, 10000000);
	Edge* bd = new Edge(b, d, 8000000);
	Edge* dc = new Edge(d, c, 6000000);
	Edge* dg = new Edge(d, g, 4000000);
	Edge* fd = new Edge(f, d, 3000000);
	Edge* af = new Edge(a, f, 9000000);
	Edge* fg = new Edge(f, g, 2000000);
	Edge* ge = new Edge(g, e, 7000000);

	Edge* ce = new Edge(c, e, 1);

	//Draw Nodes
	this->application->AddRenderable(a);
	this->application->AddRenderable(b);
	this->application->AddRenderable(c);
	this->application->AddRenderable(d);
	this->application->AddRenderable(e);
	this->application->AddRenderable(f);
	this->application->AddRenderable(g);

	//Draw Edges
	this->application->AddRenderable(ab);
	this->application->AddRenderable(bc);
	this->application->AddRenderable(bd);
	this->application->AddRenderable(dc);

	this->application->AddRenderable(dg);
	this->application->AddRenderable(fd);

	this->application->AddRenderable(af);
	this->application->AddRenderable(fg);
	this->application->AddRenderable(ge);
	this->application->AddRenderable(ce);

	this->koe = new Koetje();
	this->haas = new Haasje();

	koe->setNode(a);

	a->setBeestje(koe);

	haas->setNode(e);

	e->setBeestje(haas);

	this->application->AddRenderable(koe);
	this->application->AddRenderable(haas);

	this->aStar = new AlgoRitmeWeek1();
}


NodeMap::~NodeMap()
{
}


void NodeMap::setStates()
{
	koe->setState(new WanderingState(koe, this));
	haas->setState(new WanderingState(haas, this));
}
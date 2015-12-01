#include "NodeMap.h"
#include "WanderingState.hpp"
#include "HuntState.hpp"
#include <random>
void NodeMap::Update()
{
	this->getKoe()->Update(1.00);
	this->getHaas()->Update(1.00);
}

NodeMap::NodeMap(FWApplication* application)
{
	this->application = application;

	//x,y//
	Node* a = new Node("A", 100, 200);
	Node* b = new Node("B", 200, 100);
	Node* c = new Node("C", 370, 100);
	Node* d = new Node("D", 300, 180);
	Node* e = new Node("E", 450, 200);
	Node* f = new Node("F", 200, 300);
	Node* g = new Node("G", 330, 300);
	/*
	Node* h = new Node("H", 600, 200);
	Node* i = new Node("I", 650, 250);
	Node* j = new Node("J", 550, 300);
	Node* k = new Node("K", 450, 350);
	Node* l = new Node("l", 600, 450);*/

	this->nodeList.push_back(a);
	this->nodeList.push_back(b);
	this->nodeList.push_back(c);
	this->nodeList.push_back(d);
	this->nodeList.push_back(e);
	this->nodeList.push_back(f);
	this->nodeList.push_back(g);/*
	this->nodeList.push_back(h);
	this->nodeList.push_back(i);
	this->nodeList.push_back(j);
	this->nodeList.push_back(k);
	this->nodeList.push_back(l);*/
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
//	Edge* eh = new Edge(e, h, 700000);
	/*
	Edge* hj = new Edge(h, j, 780000);
	Edge* jl = new Edge(j, l, 10000002);

	Edge* kl = new Edge(k, l, 6000000);
	Edge* ij = new Edge(i, j, 5500000);
	Edge* gk = new Edge(g, k, 20000000);*/
	//Draw Nodes
	this->application->AddRenderable(a);
	this->application->AddRenderable(b);
	this->application->AddRenderable(c);
	this->application->AddRenderable(d);
	this->application->AddRenderable(e);
	this->application->AddRenderable(f);
	this->application->AddRenderable(g);
	/*
	this->application->AddRenderable(h);
	this->application->AddRenderable(i);
	this->application->AddRenderable(j);
	this->application->AddRenderable(k);
	this->application->AddRenderable(l);*/
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
/*	this->application->AddRenderable(eh);


	this->application->AddRenderable(jl);
	this->application->AddRenderable(hj);

	this->application->AddRenderable(ij);


	this->application->AddRenderable(kl);
	this->application->AddRenderable(gk);*/
	this->koe = new Koetje();
	this->haas = new Haasje();

	koe->setNode(a);

	a->setBeestje(koe);

	haas->setNode(e);

	koe->setTarget(haas);
	haas->setTarget(koe);
	e->setBeestje(haas);

	f->containsWeapon = true;
	f->setTexture();


	c->containsDrugs = true;
	c->setTexture();

//	i->containsDrugs = true;
//	i->setTexture();

	this->application->AddRenderable(koe);
	this->application->AddRenderable(haas);

	this->aStar = new AlgoRitmeWeek1();
}


NodeMap::~NodeMap()
{
}


void NodeMap::setStates()
{
	koe->setState(new HuntState(koe, this));
	haas->setState(new WanderingState(haas, this));
}


void NodeMap::resetNodes()
{


}
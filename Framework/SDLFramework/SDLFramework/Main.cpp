#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Node.h"
#include "Koetje.h"
#include "Haasje.h"
#include "AlgoRitmeWeek1.h"
int main()
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	//10 nodes
	//Per klik een stap van het korste pad;//checkje voor buurnode;
	//druk op 1 haasje verplaaytst
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	


	std::vector<Node*> nodeList;

	Node* a = new Node("A", 100, 200);
	Node* b = new Node("B", 200, 100);
	Node* c= new Node("C", 370, 100);
	Node* d= new Node("D", 300, 180);
	Node* e= new Node("E", 450, 200);
	Node* f= new Node("F", 200, 300);
	Node* g= new Node("G", 330, 300);

	nodeList.push_back(a);
	nodeList.push_back(b);
	nodeList.push_back(c);
	nodeList.push_back(d);
	nodeList.push_back(e);
	nodeList.push_back(f);
	nodeList.push_back(g);

	/*Node* h= new Node("H", 425, 360);
	Node* i= new Node("I", 550, 480);
	Node* j= new Node("K", 600, 378); 
	*/
	Edge* ab = new Edge(a,b,5000000);
	Edge* bc = new Edge(b,c,10000000);
	Edge* bd = new Edge(b, d,8000000);
	Edge* dc = new Edge(d, c,6000000);
	Edge* dg = new Edge(d, g,4000000);
	Edge* fd = new Edge(f, d,3000000);
	Edge* af = new Edge(a, f,9000000);
	Edge* fg = new Edge(f, g,2000000);
    Edge* ge = new Edge(g, e,7000000);

	//	Edge* de = new Edge(d,e,);
		Edge* ce = new Edge(c, e,1);

    //Draw Nodes
    application->AddRenderable(a);
	application->AddRenderable(b);
	application->AddRenderable(c);
	application->AddRenderable(d);
	application->AddRenderable(e);
	application->AddRenderable(f);
	application->AddRenderable(g);
    
    //Draw Edges
	application->AddRenderable(ab);
	application->AddRenderable(bc);
	application->AddRenderable(bd);
	application->AddRenderable(dc);

	application->AddRenderable(dg);
	application->AddRenderable(fd);

	application->AddRenderable(af);
	application->AddRenderable(fg);
	application->AddRenderable(ge);
	application->AddRenderable(ce);


	//while (true){}

	Koetje* vkoef = new Koetje();
	Haasje* haas = new Haasje();


	vkoef->setNode(a);
	a->setBeestje(vkoef);
    
	haas->setNode(e);
	e->setBeestje(haas);

	application->AddRenderable(vkoef);
	application->AddRenderable(haas);


	AlgoRitmeWeek1 week;
	//week.doAction(vkoef, nodeList,haas->getNode());

	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){
                    case SDLK_SPACE: week.doAction(vkoef, nodeList,haas);break;
				default:
					break;
				}
			}
		}
		
		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("Opdracht week 1: Bryan + Andy", 120, 500 );
		application->DrawText("Groen is koe, Oranje is haas", 120, 520);
		// For the background
	
		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
 
		application->SetColor(Color(255, 255, 255, 255));

	}
		
	return EXIT_SUCCESS;
}
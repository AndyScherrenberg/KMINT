#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Node.h"
#include "Koetje.h"
#include "Haasje.h"
int main(int args[])
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
	

	Node* a = new Node("A", 100, 200);
	Node* b = new Node("B", 200, 100);
	Node* c= new Node("C", 370, 100);
	Node* d= new Node("D", 300, 180);
	Node* e= new Node("E", 450, 200);
	Node* f= new Node("F", 200, 300);
	Node* g= new Node("G", 330, 300);






	/*Node* h= new Node("H", 425, 360);
	Node* i= new Node("I", 550, 480);
	Node* j= new Node("K", 600, 378); 
	*/
	Edge* ab = new Edge(a,b,5);
	Edge* bc = new Edge(b,c,10);
	Edge* bd = new Edge(b, d,8);
	Edge* dc = new Edge(d, c,6);
	Edge* dg = new Edge(d, g,4);
	Edge* fd = new Edge(f, d,3);
	Edge* af = new Edge(a, f,9);
	Edge* fg = new Edge(f, g,2);
		Edge* ge = new Edge(g, e,7);

	//	Edge* de = new Edge(d,e,);
		Edge* ce = new Edge(c, e,1);
	application->AddRenderable(a);
	application->AddRenderable(b);
	application->AddRenderable(c);
	application->AddRenderable(d);
	application->AddRenderable(e);
	application->AddRenderable(f);
	application->AddRenderable(g);

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
	application->AddRenderable(vkoef);
	application->AddRenderable(haas);

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

				default:
					break;
				}
			}
		}
		
		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("Opdracht week 1: Bryan + Andy", 120, 500 );
		
		// For the background
	



	

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();


		
		application->SetColor(Color(255, 255, 255, 255));

	}
		
	return EXIT_SUCCESS;
}
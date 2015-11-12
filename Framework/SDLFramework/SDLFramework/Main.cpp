#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Node.h"

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
	

	std::vector<Node*> nodes;




	for (int i = 0; i < 11; i++){
		
		nodes.push_back(new Node(i, 10*i,10*i));

	}


	//while (true){}
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
		application->DrawText("Welcome to KMint", 800 / 2, 600 / 2);
		
		// For the background
	



	

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();


		for (Node *n : nodes)
		{
			application->SetColor(Color(0, 0, 0, 0));
			application->DrawRect(n->x, n->y, n->w, n->h, true);
		}
		application->SetColor(Color(255, 255, 255, 255));

	}
		
	return EXIT_SUCCESS;
}
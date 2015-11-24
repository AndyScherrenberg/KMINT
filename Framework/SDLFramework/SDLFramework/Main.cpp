#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "NodeMap.h"
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

	NodeMap map{ application };
	map.setStates();
	char cowStatus[200];
	char rabitStatus[200];

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
				case SDLK_SPACE:
					map.Update();
					break;
				default:
					break;
				}
			}
		}
		
#ifdef __APPLE__
		strcpy(cowStatus, "Koe status = "); // copy string one into the result.
		strcat(cowStatus, map.getKoe()->getState()->stateToText());
		strcpy(rabitStatus, "Haas status = "); // copy string one into the result.
		strcat(rabitStatus, map.getHaas()->getState()->stateToText());
#else

		strcpy_s(cowStatus,"Koe status = "); // copy string one into the result.
		strcat_s(cowStatus,map.getKoe()->getState()->stateToText());
		strcpy_s(rabitStatus, "Haas status = "); // copy string one into the result.
		strcat_s(rabitStatus, map.getHaas()->getState()->stateToText());
#endif

		
		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("Opdracht week 1: Bryan + Andy", 120, 500);
		
	application->DrawText(cowStatus, 120, 540);
		application->DrawText(rabitStatus, 120, 560);
		// For the background

		//application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();

		application->SetColor(Color(255, 255, 255, 255));

	}

	return EXIT_SUCCESS;
}
#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#ifdef WIN_32
#include <SDL_events.h>
#else
#include "SDL_events.h"
#endif
#include "SDL_timer.h"
#include <time.h>
#include "CowEntity.h"
#include "RabbitEntity.h"
int main()
{

	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));

	CowEntity* cow = new  CowEntity();
	RabbitEntity* rabbit = new RabbitEntity();
	application->AddRenderable(cow);
	application->AddRenderable(rabbit);

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
			
					break;
				default:
					break;
				}
			}
        }
		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();

		application->SetColor(Color(255, 255, 255, 255));

	}

	return EXIT_SUCCESS;
}
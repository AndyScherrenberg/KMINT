#include "Haasje.h"


Haasje::Haasje()
{
	#ifdef __APPLE__
        this->SetTexture(mApplication->LoadTexture("/Users/bryansijs/Documents/C++/KMINTMac/KMINT/Framework/SDLFramework/Resources/haas.png"));
    #else
        this->SetTexture(mApplication->LoadTexture("haas.png"));
    #endif

		this->StateMap.insert(std::pair<int, int>(1, 5));
		this->StateMap.insert(std::pair<int, int>(5, 1));

		
}


Haasje::~Haasje()
{
}


void Haasje::Draw(){

    mApplication->DrawTexture(this->GetTexture(), this->getNode()->x, this->getNode()->y,50,50);
    mApplication->SetColor(Color(0, 155, 0, 255));
}
void Haasje::Update(float deltaTime) {
    this->currentState->checkState();
    this->currentState->Update();
}


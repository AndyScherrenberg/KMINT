#include "Haasje.h"


Haasje::Haasje()
{
	#ifdef __APPLE__
        this->SetTexture(mApplication->LoadTexture("/Users/bryansijs/Documents/C++/KMINTMac/KMINT/Framework/SDLFramework/Resources/haas.png"));
    #else
        this->SetTexture(mApplication->LoadTexture("haas.png"));
    #endif
}


Haasje::~Haasje()
{
}


void Haasje::Draw(){

    mApplication->DrawTexture(this->GetTexture(), this->getNode()->x, this->getNode()->y,50,50);
    mApplication->SetColor(Color(0, 155, 0, 255));
	//mApplication->DrawRect(this->getNode()->x - 12, this->getNode()->y - 12, 10, 10, true);
}
void Haasje::Update(float deltaTime) {
    this->currentState->checkState();
    this->currentState->Update();
}


#include "Koetje.h"


Koetje::Koetje()
{
#ifdef __APPLE__
    this->SetTexture(mApplication->LoadTexture("/Users/bryansijs/Documents/C++/KMINTMac/KMINT/Framework/SDLFramework/Resources/cow-2.png"));
#else
    this->SetTexture(mApplication->LoadTexture("cow-2.png"));
#endif
}


Koetje::~Koetje()
{

}

void Koetje::Draw(){

	mApplication->DrawTexture(this->GetTexture(), this->getNode()->x, this->getNode()->y,50,50);
	mApplication->SetColor(Color(0, 155, 0, 255));
}
void Koetje::Update(float deltaTime) {
    this->currentState->checkState();
    this->currentState->Update();
}


#include "Haasje.h"


Haasje::Haasje()
{
	#ifdef __APPLE__
        this->SetTexture(mApplication->LoadTexture("/Users/bryansijs/Documents/C++/KMINTMac/KMINT/Framework/SDLFramework/Resources/haas.png"));
    #else
        this->SetTexture(mApplication->LoadTexture("haas.png"));
    #endif
		this->setWander(3);



		this->StateMap.insert(std::make_pair<int, int>(1, 2));
		this->StateMap.insert(std::make_pair<int, int>(1, 5));
		this->StateMap.insert(std::make_pair<int, int>(2, 4));
		this->StateMap.insert(std::make_pair<int, int>(4, 1));
		this->StateMap.insert(std::make_pair<int, int>(4, 2));
		this->StateMap.insert(std::make_pair<int, int>(4, 5));
		this->StateMap.insert(std::make_pair<int, int>(5, 2));
		setBaseSate(1);	setBadDrugState(5);

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


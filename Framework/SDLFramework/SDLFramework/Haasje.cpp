#include "Haasje.h"


Haasje::Haasje()
{
	this->SetTexture(mApplication->LoadTexture("Haas.png"));
	
}


Haasje::~Haasje()
{
}


void Haasje::Draw(){

	mApplication->DrawTexture(this->GetTexture(), 0, 0);

	mApplication->SetColor(Color(255, 105, 0, 255));
	mApplication->DrawRect(this->getNode()->x - 12, this->getNode()->y - 12, 10, 10, true);
}
void Haasje::Update(float deltaTime) {


}


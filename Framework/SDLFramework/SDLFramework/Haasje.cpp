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


}
void Haasje::Update(float deltaTime) {


}


#include "Koetje.h"


Koetje::Koetje()
{
	this->SetTexture(mApplication->LoadTexture("Koe.png"));
}


Koetje::~Koetje()
{
}

void Koetje::Draw(){

	mApplication->DrawTexture(this->GetTexture(), 0, 0);


}
void Koetje::Update(float deltaTime) {


}


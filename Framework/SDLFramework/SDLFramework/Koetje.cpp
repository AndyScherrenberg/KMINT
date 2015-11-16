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
	mApplication->SetColor(Color(0, 155, 0, 255));
	mApplication->DrawRect(this->getNode()->x - 12, this->getNode()->y - 12, 10, 10, true);

}
void Koetje::Update(float deltaTime) {


}


#include "Node.h"


Node::Node()
{

}


Node::~Node()
{
}


void Node::Draw(){ 
	mApplication->SetColor(Color(255, 105, 180, 255));
	mApplication->DrawRect(x-12,y-12,h,w,true);

	if (this->containsDrugs || this->containsWeapon)
	{
		mApplication->DrawTexture(this->GetTexture(), x - 12, y-12, 50, 50);
	}

	mApplication->SetColor(Color(0, 0, 0, 255));
	mApplication->DrawText(ch, x , y-16 );

}
void Node::Update(float deltaTime) {
}


void Node::setTexture()
{

	if (this->containsDrugs){
#ifdef __APPLE__
		this->SetTexture(mApplication->LoadTexture("/Users/bryansijs/Documents/C++/KMINTMac/KMINT/Framework/SDLFramework/Resources/haas.png"));
#else
		this->SetTexture(mApplication->LoadTexture("pill.png"));
#endif
	}

	else if (this->containsWeapon)
	{
#ifdef __APPLE__
        this->SetTexture(mApplication->LoadTexture("/Users/bryansijs/Documents/C++/KMINTMac/KMINT/Framework/SDLFramework/Resources/boot.png"));
#else
        this->SetTexture(mApplication->LoadTexture("boot.png"));
#endif
	}


}
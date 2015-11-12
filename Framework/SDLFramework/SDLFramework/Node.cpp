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
	mApplication->SetColor(Color(0, 0, 0, 255));
	mApplication->DrawText(ch, x , y-16 );

}
void Node::Update(float deltaTime) {}
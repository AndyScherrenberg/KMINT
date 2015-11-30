#include "Haasje.h"


Haasje::Haasje()
{
	#ifdef __APPLE__
        this->SetTexture(mApplication->LoadTexture("/Users/bryansijs/Documents/C++/KMINTMac/KMINT/Framework/SDLFramework/Resources/haas.png"));
    #else
        this->SetTexture(mApplication->LoadTexture("haas.png"));
    #endif
		this->setWander(3);

		this->StateMap.insert(std::make_pair<int, int>(1, 2)); // Wander -> find
		this->StateMap.insert(std::make_pair<int, int>(1, 5)); //Wander ->sleep
		this->StateMap.insert(std::make_pair<int, int>(2, 4)); //find -> hunt
		this->StateMap.insert(std::make_pair<int, int>(4, 1)); //hunt -> wander
		this->StateMap.insert(std::make_pair<int, int>(4, 2)); //hunt -> find
		this->StateMap.insert(std::make_pair<int, int>(4, 5)); //hunt -> Sleep
		this->StateMap.insert(std::make_pair<int, int>(5, 2)); //Sleep ->find
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
    calculateChancePercentage();
}

int Haasje::getWanderChancePercentage(){
    return wanderChancePercentage;
}

int Haasje::getSleepChancePercentage(){
    return sleepChancePercentage;
}

int Haasje::getFindChancePercentage(){
    return findChancePercentage;
}

int Haasje::getHuntChancePercentage(){
    return huntChancePercentage;
}

void Haasje::calculateChancePercentage(){
   
    if (sleepChance < 0) {
        sleepChance = 0;
    }
    int total = sleepChance + findChance + wanderChance + huntChance;
    
    huntChancePercentage = (huntChance*100)/total;
    sleepChancePercentage = (sleepChance*100)/total;
    findChancePercentage = (findChance*100)/total;
    wanderChancePercentage = (wanderChance*100)/total;
}



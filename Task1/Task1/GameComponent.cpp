//GameComponent.cpp

#include "stdafx.h"
#include "GameComponent.h"

int GameComponent::instances = 0;

GameComponent::GameComponent()
{

	instances++;//dynamic, will increment
	id = instances;
	
}

void GameComponent::Update(const tm* eventTime)
{
	//ID 1
	printf("ID: %d Updated @ %02d-%02d-%02d\n", id, eventTime->tm_hour, eventTime->tm_min, eventTime->tm_sec);

}
int GameComponent::getId(){
	return id;
}
GameComponent::~GameComponent()
{
}

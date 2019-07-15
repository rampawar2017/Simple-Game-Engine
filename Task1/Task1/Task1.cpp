// Task1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Game.h"
#include "DrawableGameComponent.h"

void displayInit(){
	printf("Initialising game\n");
}
void displayTerminate(){
	printf("terminating game\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	Game* pGame = new Game(2);
	pGame->SetInitialise(displayInit);
	pGame->SetTerminate(displayTerminate);
	GameComponent* pGameComponent = new GameComponent();
	pGame->Add(pGameComponent);
	DrawableGameComponent* pDrawableGameComponent = new DrawableGameComponent(0, 0);
	pGame->Add(pDrawableGameComponent);
	pGame->Run();
	return 0;
}


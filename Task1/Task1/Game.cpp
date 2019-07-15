//Game.cpp

#include "stdafx.h"
#include "Game.h"
#include <time.h>

Game::Game(int maxComponent)
{
	componentCount = maxComponent;
	components = new GameComponent*[maxComponent];

	initialise = NULL;
	terminate = NULL;
}

void Game::Add(GameComponent* pGameComponent){
	components[pGameComponent->getId()-1] = pGameComponent;

}

void Game::SetInitialise(FP init){
	initialise = init;
}

void Game::SetTerminate(FP term){
	terminate = term;
}
void Game::Run(){
	
	if (initialise != NULL)
		(*initialise)();
	int nIndex = 0, nTimeCnt = 0;
	time_t time_1;
	tm tt;
	clock_t start, end;
	start = clock();
	while(true){
		//Bullet No. 4 of instructions
		GameComponent* pComponent = (GameComponent*)components[nIndex];		
		
		time( &time_1 ); 
		localtime_s(&tt, &time_1);
		pComponent->Update(&tt);
		end = clock();
		if(componentCount<=pComponent->getId())
		{
			// wait for a second
			while(true){
				end = clock();
				if((end - start)>TICKS_1000MS)
					break;
			}
			nTimeCnt++;
			// check if 5 seconds are passed
			if(nTimeCnt>=5)
				break;
			
			start = clock();
			nIndex = 0;
			continue;
		}
		nIndex++;

	}
	if (terminate != NULL)
		(*terminate)();
}
Game::~Game()
{
}

//Game.h
#pragma once
#include "GameComponent.h"
typedef  void (*FP)(void);

class Game
{
	int componentCount;
	GameComponent** components;
	FP initialise;
	FP terminate;
	static const int TICKS_1000MS = 1000;
public:
	Game(int maxComponent);
	void Add(GameComponent*);
	void Run();
	void SetInitialise(FP init);
	void SetTerminate(FP term);
	~Game(void);
};


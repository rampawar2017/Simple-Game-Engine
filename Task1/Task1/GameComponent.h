//GameComponent.h
#pragma once //preprocessor directive designed to cause the current source file to be included only once in a single compilation

class GameComponent
{
protected:
	int id;
public:
	static int instances;
public:
	GameComponent();
	~GameComponent();
	int getId();
	virtual void Update(const tm*);
};


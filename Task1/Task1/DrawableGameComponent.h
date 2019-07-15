//DrawableGameComponent.h

#pragma once
#include "GameComponent.h"
enum Direction {
	Left,
	Right,
	Up,
	Down
};
class DrawableGameComponent: public GameComponent
{
private:
	int x;
	int y;
	void ChangeDirection();
	void Draw();
public:
	Direction direction;
	DrawableGameComponent(int x, int y);
	static const int SCREEN_WIDTH = 80;
	static const int SCREEN_HEIGHT = 20;
	void Update(const tm* eventTime);
	~DrawableGameComponent();
};


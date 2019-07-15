//DrawableGameComponent.cpp

#include "stdafx.h"
#include "DrawableGameComponent.h"


DrawableGameComponent::DrawableGameComponent(int x, int y)
{
	this->x = x;
	this->y = y;
	direction = Right;

}
void DrawableGameComponent::Update(const tm* eventTime)
{
	printf("ID: %d Updated @ %02d-%02d-%02d\n", id, eventTime->tm_hour, eventTime->tm_min, eventTime->tm_sec);
	if(direction == Up){
		y--;
		if(y == -1)
			y = 0;
	}
	else if(direction == Down){
		y++;
		if(y > SCREEN_HEIGHT)
			y = 20;
	}
	else if(direction == Right){
		x++;
		if(x > SCREEN_WIDTH)
			x = 80;
	}
	else if(direction == Left){
		x--;
		if(x == -1)
			x = 0;
	}
	Draw();
	ChangeDirection();
}
void DrawableGameComponent::ChangeDirection(){
	int nRand = rand() % 4;
	while(direction == nRand)
		nRand = rand() % 4;
	if(nRand == 0)
		direction = Left;
	else if(nRand == 1)
		direction = Right;
	else if(nRand == 2)
		direction = Up;
	else 
		direction = Down;

}
void DrawableGameComponent::Draw(){
	if(direction = Up)
		printf("Up : X:%d Y:%d\n", x, y);
	else if(direction == Down)
		printf("Down : X:%d Y:%d\n", x, y);
	else if(direction == Left)
		printf("Left : X:%d Y:%d\n", x, y);
	else if(direction == Right)
		printf("Right : X:%d Y:%d\n", x, y);
}
DrawableGameComponent::~DrawableGameComponent()
{
}

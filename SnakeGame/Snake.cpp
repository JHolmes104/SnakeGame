#include "Snake.h"

Snake::Snake()
{

}

Snake::Snake(int xInput, int yInput, int playerInput)
{
	x - xInput;
	y = yInput;
	playerNumber = playerInput;
	inWater = false;
	nextSnake = nullptr;
}

Snake::Snake(int xInput, int yInput, int playerInput, Snake* nextSnakeInput)
{
	x - xInput;
	y = yInput;
	playerNumber = playerInput;
	nextSnake = nextSnakeInput;
}

int Snake::getX(void)
{
	return x;
}

void Snake::setX(int xInput)
{
	x += xInput;
}

int Snake::getY(void)
{
	return y;
}

void Snake::setY(int yInput)
{
	y += yInput;
}
#include "Snake.h"

Snake::Snake()
{

}

Snake::Snake(int xInput, int yInput)
{
	x - xInput;
	y = yInput;
}

int Snake::getX()
{
	return x;
}

int Snake::getY()
{
	return y;
}

void Snake::capacityChange()
{
	if (inWater == true)
	{
		currentLungCapacity -= capacityDecrease;
	}
	else
	{
		currentLungCapacity += capacityIncrease;
	}

	if (currentLungCapacity < 0)
	{
		currentLungCapacity = 0;
	}

	if (currentLungCapacity > maxLungCapacity)
	{
		currentLungCapacity = maxLungCapacity;
	}
}
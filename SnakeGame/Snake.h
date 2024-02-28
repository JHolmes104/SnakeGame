#pragma once
class Snake
{
private:
	int x;
	int y;
	
	bool inWater;
	int playerNumber;

public:
	Snake(void);
	Snake(int xInput, int yInput, int playerInput);
	Snake(int xInput, int yInput, int playerNumberInput, Snake* nextSnakeInput);

	int getX(void);
	void setX(int xInput);
	int getY(void);
	void setY(int yInput);
	int getPlayerNumber(void);
	
	Snake* nextSnake;
};


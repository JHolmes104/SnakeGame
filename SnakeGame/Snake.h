#pragma once
class Snake
{
private:
	int x;
	int y;
	
	int currentLungCapacity;
	int maxLungCapacity;
	int capacityDecrease;
	int capacityIncrease;
	bool inWater;
public:
	Snake(void);
	Snake(int xInput, int yInput);
	int getX(void);
	int getY(void);
	void capacityChange(void);
	Snake* nextSnake;
};


#pragma once
#include "Snake.h"
#include "Game.h"
class Player
{
private:
	int x; int y;
	int direction;
	int size;
	int currentLungCapacity;
	int playerNumber;

	Game* currentGame;

public:
	Player();
	Player(int playerNumberInput, Game* thisGame);

	Snake* snakeHead;

	void setDirection(void);

	void move(void);
};

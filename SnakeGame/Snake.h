#pragma once
#include <SFML/Graphics.hpp>

class Snake
{
private:
	int x;
	int y;
	
	bool inWater;
	int playerNumber;

	Snake* nextSnake;

public:
	Snake(void);
	Snake(int xInput, int yInput, int playerInput);

	~Snake();

	int getX(void);
	void setX(int xInput);
	int getY(void);
	void setY(int yInput);
	int getPlayerNumber(void);

	void draw(sf::RenderWindow& window);
	void setNextSnake(void);
};


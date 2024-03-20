#pragma once
#include <SFML/Graphics.hpp>

class Snake
{
private:
	int x;
	int y;
	
	bool inWater;
	int playerNumber;

	sf::Color playerColor;
public:
	Snake(void);
	Snake(int xInput, int yInput, int playerInput);

	~Snake();

	Snake* nextSnake;

	int getX(void);
	void setX(int xInput);

	int getY(void);
	void setY(int yInput);
	
	int getPlayerNumber(void);

	void draw(sf::RenderWindow& window);
	void setNextSnake(Snake* newSnake);
	void shiftSnakes(int newX, int newY);

	void removeEnd(void);
	void sink(void);
};


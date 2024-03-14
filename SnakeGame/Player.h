#pragma once
#include <SFML/Graphics.hpp>

class LungBar;

class Snake;

class Player
{
private:
	int x; int y;
	int direction;
	int size;

	int currentLungCapacity;
	int maxLungCapacity;
	
	int playerNumber;
	int score;

	bool snakeCreated;

public:
	Player();
	Player(int playerNumberInput, int maxCapacityInput);

	~Player();

	Snake* snakeHead;

	LungBar* lungbar;

	void setDirection(void);
	void setDirection(int newDirection);

	void draw(sf::RenderWindow& window);

	void move(void);
	int getSize(void);

	int getScore(void);
	void setScore(void);

	bool getSnakeCreated(void);
	void setSnakeCreated(bool newSC);

	void breathe(int screenHeight, int waterCap, int drainRate);

	void removeEnd(void);

	void sink(void);
};
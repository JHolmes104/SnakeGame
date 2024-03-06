#pragma once
#include <SFML/Graphics.hpp>

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
public:
	Player();
	Player(int playerNumberInput, int maxCapacityInput);

	~Player();

	Snake* snakeHead;

	void setDirection(void);

	void draw(sf::RenderWindow& window);

	void move(void);
	int getSize(void);

	int getScore(void);
	void setScore(void);
};

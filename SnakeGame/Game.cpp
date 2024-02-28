#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game(int lCapInput, int lCapDecreaseInput, int lCapIncreaseInput, int wCapInput, float speedInput)
{
	lungCapacity = lCapInput;
	capacityDecrease = lCapDecreaseInput;
	capacityIncrease = lCapIncreaseInput;
	
	waterCapacity = wCapInput;
	waterDrainRate = waterCapacity / 90;

	moveSpeed = speedInput;

	player1 = Player(1, this);
}

void Game::update()
{
	sf::RectangleShape snake;
	snake.setSize(sf::Vector2f(20, 20));
	snake.setFillColor(sf::Color::Green);
	snake.setPosition(player1.snakeHead->getX(), player1.snakeHead->getY());
	snake.setOrigin(10, 10);

	sf::RenderWindow window(sf::VideoMode(800, 600), "MyWindow");
	while (window.isOpen())
	{
		player1.setDirection();
		player1.move();
		snake.setPosition(player1.snakeHead->getX(), player1.snakeHead->getY());
	}
}

int Game::getLungCapacity(void)
{
	return lungCapacity;
}
int Game::getCapacityDecrease(void)
{
	return capacityDecrease;
}
int Game::getCapacityIncrease(void)
{
	return capacityIncrease;
}

int Game::getWaterCapacity(void)
{
	return waterCapacity;
}
float Game::getWaterDrainRate(void)
{
	return waterDrainRate;
}
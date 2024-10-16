#include "Snake.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Snake::Snake()
{
	x = 100;
	y = 100;
	playerNumber = 1;
	inWater = false;
	nextSnake = nullptr;
}

Snake::Snake(int xInput, int yInput, int playerInput)
{
	x = xInput;
	y = yInput;
	playerNumber = playerInput;
	inWater = false;
	nextSnake = nullptr;

	if (playerNumber == 1)
	{
		std::cout << "Player 1 is green" << std::endl;
		playerColor = sf::Color(0, 255, 0, 255);
	}

	else if (playerNumber == 2)
	{
		std::cout << "Player 2 is red" << std::endl;
		playerColor = sf::Color(255, 0, 0, 255);
	}
}

Snake::~Snake()
{
	if (nextSnake != nullptr)
	{
		nextSnake->~Snake();
	}
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

int Snake::getPlayerNumber(void)
{
	return playerNumber;
}

void Snake::draw(sf::RenderWindow& window)
{
	sf::RectangleShape snake;
	snake.setSize(sf::Vector2f(20, 20));
	snake.setFillColor(playerColor);
	snake.setOrigin(10, 10);
	snake.setPosition(getX(), getY());
	window.draw(snake);

	if (nextSnake != nullptr)
	{
		nextSnake->draw(window);
	}
}

void Snake::setNextSnake(Snake* newSnake)
{
	if (nextSnake == nullptr)
	{
		std::cout << "Nullptr" << std::endl << x << ", " << y << std::endl;
		nextSnake = newSnake;
	}

	else
	{
		std::cout << "No nullptr" << std::endl;
		newSnake->setX(nextSnake->getX());
		newSnake->setY(nextSnake->getY());
		nextSnake->setNextSnake(newSnake);
	}
}

void Snake::shiftSnakes(int newX, int newY)
{
	if (nextSnake != nullptr)
	{
		nextSnake->shiftSnakes(x, y);
	}

	x = newX;
	y = newY;
}

void Snake::removeEnd(void)
{
	if (nextSnake->nextSnake != nullptr)
	{
		nextSnake->removeEnd();
	}
	else
	{
		nextSnake->~Snake();
		nextSnake = nullptr;
	}
}

void Snake::sink(void)
{
	setY(20);
	if (nextSnake != nullptr)
	{
		nextSnake->sink();
	}
}
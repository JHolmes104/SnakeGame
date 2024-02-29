#include "Snake.h"

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
	snake.setFillColor(sf::Color::Green);

	snake.setPosition(getX(), getY());
	snake.setOrigin(10, 10);
	window.draw(snake);

	if (nextSnake != nullptr)
	{
		nextSnake->draw(window);
	}
}

void Snake::setNextSnake(void)
{

}
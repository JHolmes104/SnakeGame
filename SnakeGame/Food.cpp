#include "Food.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Food::Food(void)
{

}

Food::Food(int screenWidth, int screenHeight, int offset, int waterCapacity)
{
	int xMod = screenWidth / 20;
	xMod -= 2;

	int yMod = waterCapacity / 20;
	yMod -= 2;

	x = (rand() % xMod) * 20;
	y = (rand() % yMod) * 20;

	y += (screenHeight - waterCapacity);

	x += offset;
	y += offset;

	eaten = true;
}

Food::~Food(void)
{

}

void Food::initialise(int screenWidth, int screenHeight, int offset, int waterCapacity)
{
	int xMod = screenWidth / 20;
	xMod -= 2;

	int yMod = waterCapacity / 20;
	yMod -= 2;

	x = (rand() % xMod) * 20;
	y = (rand() % yMod) * 20;

	y += (screenHeight - waterCapacity);

	x += offset;
	y += offset;

	eaten = false;
}

int Food::getX(void)
{
	return x;
}

int Food::getY(void)
{
	return y;
}

bool Food::getEaten(void)
{
	return eaten;
}

void Food::draw(sf::RenderWindow& window)
{
	sf::RectangleShape food;
	food.setSize(sf::Vector2f(20, 20));
	food.setFillColor(sf::Color::Yellow);
	food.setOrigin(10, 10);
	food.setPosition(x, y);
	window.draw(food);
}

void Food::eat(void)
{
	eaten = true;
}

void Food::sink(int waterCapacity, int screenHeight)
{
	if ((screenHeight - waterCapacity) > y)
	{
		waterCapacity -= waterCapacity % 20;
		y = screenHeight - waterCapacity;
	}
}
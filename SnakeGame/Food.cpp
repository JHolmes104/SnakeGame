#include "Food.h"
#include <SFML/Graphics.hpp>

Food::Food(void)
{

}

Food::Food(int screenWidth, int screenHeight, int offset)
{
	int xMod = screenWidth / 20;
	xMod *= 20;
	xMod -= (2 * offset);

	int yMod = screenHeight / 20;
	yMod *= 20;
	yMod -= (2 * offset);

	x = rand() % xMod;
	y = rand() % yMod;

	x += offset;
	y += offset;

	eaten = false;
}

Food::~Food(void)
{

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
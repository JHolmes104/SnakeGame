#include "LungBar.h"
#include <SFML/Graphics.hpp>

LungBar::LungBar()
{

}

LungBar::LungBar(int capacity, int playerNum)
{
	maxCapacity = capacity;
	currentCapacity = capacity;

	if (playerNum == 1)
	{
		playerFillColor = sf::Color(0,255, 0, 255);
		playerOutlineColor = sf::Color(0, 128, 0, 255);
		xPos = 10;
	}

	if (playerNum == 2)
	{
		playerFillColor = sf::Color(255, 0, 0, 255);
		playerOutlineColor = sf::Color(128, 0, 0, 255);
	}
}

void LungBar::draw(sf::RenderWindow& window)
{
	sf::RectangleShape background;
	background.setFillColor(playerOutlineColor);
	background.setPosition(xPos, 10);
	background.setSize(sf::Vector2f(170, 30));

	sf::RectangleShape fill;
	fill.setFillColor(playerFillColor);
	fill.setPosition(xPos + 5, 15);
	int chunkLength = 160 / maxCapacity;
	int fillLength = currentCapacity * chunkLength;
	fill.setSize(sf::Vector2f(fillLength, 20));

	window.draw(background);
	window.draw(fill);
}

void LungBar::updateCapacity(int capacity)
{
	currentCapacity = capacity;
}
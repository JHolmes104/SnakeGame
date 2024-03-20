#pragma once
#include <SFML/Graphics.hpp>

class LungBar
{
private:
	int maxCapacity;
	int currentCapacity;
	int xPos;
	int score;

	sf::Color playerFillColor;
	sf::Color playerOutlineColor;

public:
	LungBar();
	LungBar(int capacity, int playerNum);
	void draw(sf::RenderWindow& window);
	void updateStats(int capacity, int newScore);
};


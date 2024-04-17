#pragma once
#include <SFML/Graphics.hpp>

class WinScreen
{
private:
	int winner;
	int score;

	void update(void);
	void draw(sf::RenderWindow& window);

	sf::Font snakeFont;
	sf::Color winnerColor;

public:
	WinScreen(int winnerInput, int scoreInput);
};


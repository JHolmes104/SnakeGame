#pragma once
#include <SFML/Graphics.hpp>

class WinScreen
{
private:
	int winner;
	int score;

	void update(void);
	void initialiseShapes(void);
	void draw(sf::RenderWindow& window);

	sf::Font snakeFont;
	sf::Color winnerColor;

	sf::Text winnerText;
	sf::Text scoreText;
	sf::Text mainMenuText;
	sf::RectangleShape mainMenuBackground;

public:
	WinScreen(int winnerInput, int scoreInput);
};



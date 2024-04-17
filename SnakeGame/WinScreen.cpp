#include "WinScreen.h"
#include <SFML/Graphics.hpp>

WinScreen::WinScreen(int winnerInput, int scoreInput)
{
	winner = winnerInput;
	score = scoreInput;

	snakeFont.loadFromFile("SnakeChan-YdV8.ttf");
	
	if (winner == 0)
	{
		winnerColor = sf::Color::White;
	}
	else if (winner == 1)
	{
		winnerColor = sf::Color::Green;
	}
	else if (winner == 2)
	{
		winnerColor = sf::Color::Red;
	}

	update();
}

void WinScreen::update(void)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Win Screen");
	while (window.isOpen())
	{
		draw(window);

	}
}

void WinScreen::draw(sf::RenderWindow& window)
{
	sf::Text winnerText;
	
	if (winner == 0)
	{
		winnerText.setString("Draw");
		winnerText.setPosition(sf::Vector2f(340, 100));
		winnerText.setCharacterSize(40);
	}
	else
	{
		winnerText.setString("Player " + std::to_string(winner) + " Wins!");
		winnerText.setPosition(sf::Vector2f(235, 100));
		winnerText.setCharacterSize(30);
	}

	winnerText.setFont(snakeFont);
	winnerText.setFillColor(winnerColor);

	window.clear(sf::Color::Black);
	window.draw(winnerText);
	window.display();
}
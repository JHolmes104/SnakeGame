#include "WinScreen.h"
#include <SFML/Graphics.hpp>
#include "MainMenu.h"

WinScreen::WinScreen(int winnerInput, int scoreInput)
{
	winner = winnerInput;
	score = scoreInput;

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
	initialiseShapes();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Win Screen");
	while (window.isOpen())
	{
		draw(window);
		mouseInputs(window);

		sf::Event event;
		window.pollEvent(event);
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		default:
			break;
		}
	}
}

void WinScreen::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	window.draw(winnerText);
	window.draw(scoreText);
	window.draw(mainMenuBackground);
	window.draw(mainMenuText);
	window.display();
}

void WinScreen::initialiseShapes(void)
{
	snakeFont.loadFromFile("SnakeChan-YdV8.ttf");

	if (winner == 0)
	{
		winnerText.setString("Draw");
		winnerText.setPosition(sf::Vector2f(340, 100));
		winnerText.setCharacterSize(40);

		scoreText.setString("Both players scored " + std::to_string(score) + " points!");
		scoreText.setPosition(sf::Vector2f(75, 200));
		scoreText.setCharacterSize(30);
	}
	else
	{
		winnerText.setString("Player " + std::to_string(winner) + " Wins!");
		winnerText.setPosition(sf::Vector2f(250, 100));
		winnerText.setCharacterSize(30);

		scoreText.setString("Player " + std::to_string(winner) + " scored " + std::to_string(score) + " points!");
		scoreText.setPosition(sf::Vector2f(125, 200));
		scoreText.setCharacterSize(30);
	}

	winnerText.setFont(snakeFont);
	winnerText.setFillColor(winnerColor);

	scoreText.setFont(snakeFont);
	scoreText.setFillColor(winnerColor);

	mainMenuText.setString("Return to\nMain Menu");
	mainMenuText.setPosition(sf::Vector2f(325, 420));
	mainMenuText.setCharacterSize(20);
	mainMenuText.setFont(snakeFont);
	mainMenuText.setFillColor(sf::Color::Red);

	mainMenuBackground.setPosition(sf::Vector2f(310, 410));
	mainMenuBackground.setSize(sf::Vector2f(180, 70));
	mainMenuBackground.setFillColor(sf::Color(128, 0, 0));
}

void WinScreen::mouseInputs(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	int x = mousePos.x;
	int y = mousePos.y;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (x >= 310 && x <= 490)
		{
			if (y >= 410 && y <= 480)
			{
				window.close();
				MainMenu();
			}
		}
	}
}
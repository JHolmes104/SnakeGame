#include "MainMenu.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

MainMenu::MainMenu()
{
	update();
}

void MainMenu::update(void)
{
	initialiseShapes();

	sf::RenderWindow window(sf::VideoMode(800,600), "Main Menu");
	while (window.isOpen())
	{ 
		draw(window);

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

void MainMenu::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	window.draw(titleText);
	window.draw(gameBox);
	window.draw(gameText);
	window.display();
}

void MainMenu::initialiseShapes()
{
	snakeFont.loadFromFile("SnakeChan-YdV8.ttf");

	titleText.setString("Snake");
	titleText.setFont(snakeFont);
	titleText.setCharacterSize(80);
	titleText.setFillColor(sf::Color::White);
	titleText.setPosition(sf::Vector2f(235, 60));

	gameText.setString("Start game");
	gameText.setFont(snakeFont);
	gameText.setCharacterSize(30);
	gameText.setFillColor(sf::Color::Green);
	gameText.setPosition(sf::Vector2f(280, 300));

	gameBox.setPosition(sf::Vector2f(265, 285));
	gameBox.setSize(sf::Vector2f(265, 65));
	gameBox.setFillColor(sf::Color(0, 128, 0));
}

void MainMenu::mouseInputs(sf::RenderWindow& window)
{
}

void MainMenu::startGame(void)
{
	Game game(20, 1, 100, 500, 0.2f);
	game.update();
}
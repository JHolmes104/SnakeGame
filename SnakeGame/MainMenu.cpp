#include "MainMenu.h"

#include "Game.h"
#include "Settings.h"

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

MainMenu::MainMenu()
{
	std::cout << "New Main Menu" << std::endl;
	update();
}

void MainMenu::update(void)
{
	initialiseShapes();

	sf::RenderWindow window(sf::VideoMode(800,600), "Main Menu");
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

void MainMenu::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	window.draw(titleText);

	window.draw(gameBox);
	window.draw(gameText);
	
	window.draw(settingsBox);
	window.draw(settingsText);

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

	settingsText.setString("Settings");
	settingsText.setFont(snakeFont);
	settingsText.setCharacterSize(30);
	settingsText.setFillColor(sf::Color::Cyan);
	settingsText.setPosition(310, 450);

	settingsBox.setPosition(265, 435);
	settingsBox.setSize(sf::Vector2f(265, 65));
	settingsBox.setFillColor(sf::Color::Blue);
}

void MainMenu::mouseInputs(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	int x = mousePos.x;
	int y = mousePos.y;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (x >= 265 && x <= 530)
		{
			if (y >= 285 && y <= 350)
			{
				window.close();
				startGame();
			}

			if (y >= 435 && y <= 500)
			{
				window.close();
				Settings();
			}
		}
	}
}

void MainMenu::startGame(void)
{
	loadModifiers();
	Game game(lungCap, lungDecrease, waterCap, moveSpeed);
	game.update();
}

void MainMenu::setGameStats(void)
{
	std::ofstream output;
	output.open("savedMods.txt");
	if (output.fail())
	{
		std::cout << "File could not be loaded";
	}
	else
	{
		output << "20\t1\t500\t0.2f";
		output.close();
	}
}

void MainMenu::loadModifiers(void)
{
	std::ifstream input;
	input.open("savedMods.txt");

	input >> lungCap >> lungDecrease >> waterCap >> moveSpeed;

	input.close();
}
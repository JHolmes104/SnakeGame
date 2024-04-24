#include "Settings.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>

Settings::Settings(void)
{
	loadCurrentSave();
	update();
}

void Settings::loadCurrentSave(void)
{
	std::ifstream input;
	input.open("savedMods.txt");

	input >> lungCap >> lungDecrease >> waterCap >> moveSpeed;

	input.close();
}

void Settings::update(void)
{
	initialiseShapes();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Settings");
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

void Settings::initialiseShapes(void)
{
	snakeFont.loadFromFile("SnakeChan-YdV8.ttf");

	titleText.setString("Settings");
	titleText.setFont(snakeFont);
	titleText.setPosition(sf::Vector2f(270, 50));
	titleText.setCharacterSize(40);
	titleText.setFillColor(sf::Color::White);



	lungCapBox.setPosition(sf::Vector2f(90, 210));
	lungCapBox.setSize(sf::Vector2f(225, 65));
	lungCapBox.setFillColor(sf::Color::White);
	
	lungCapText.setString("Lung Capacity:\n" + std::to_string(lungCap));
	lungCapText.setFont(snakeFont);
	lungCapText.setPosition(sf::Vector2f(100, 220));
	lungCapText.setCharacterSize(20);
	lungCapText.setFillColor(sf::Color::Black);



	lungDecBox.setPosition(sf::Vector2f(90, 310));
	lungDecBox.setSize(sf::Vector2f(260, 65));
	lungDecBox.setFillColor(sf::Color(128, 0, 0));

	lungDecText.setString("Lung Drain Rate:\n" + std::to_string(lungDecrease));
	lungDecText.setFont(snakeFont);
	lungDecText.setPosition(sf::Vector2f(100, 320));
	lungDecText.setCharacterSize(20);
	lungDecText.setFillColor(sf::Color::Red);



	waterBox.setPosition(sf::Vector2f(490, 210));
	waterBox.setSize(sf::Vector2f(255, 65));
	waterBox.setFillColor(sf::Color::Blue);

	waterText.setString("Water Capacity:\n" + std::to_string(waterCap));
	waterText.setFont(snakeFont);
	waterText.setPosition(sf::Vector2f(500, 220));
	waterText.setCharacterSize(20);
	waterText.setFillColor(sf::Color::Cyan);



	moveBox.setPosition(sf::Vector2f(490, 310));
	moveBox.setSize(sf::Vector2f(255, 65));
	moveBox.setFillColor(sf::Color(0, 128, 0));

	moveText.setString("Movement Speed:\n" + std::to_string(moveSpeed));
	moveText.setFont(snakeFont);
	moveText.setPosition(sf::Vector2f(500, 320));
	moveText.setCharacterSize(20);
	moveText.setFillColor(sf::Color::Green);
}

void Settings::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	window.draw(titleText);

	window.draw(lungCapBox);
	window.draw(lungCapText);

	window.draw(lungDecBox);
	window.draw(lungDecText);

	window.draw(waterBox);
	window.draw(waterText);

	window.draw(moveBox);
	window.draw(moveText);

	window.display();
}
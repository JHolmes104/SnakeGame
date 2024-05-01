#include "Settings.h"

#include <SFML/Graphics.hpp>
#include "MainMenu.h"

#include <iostream>
#include <fstream>

Settings::Settings(void)
{
	loadCurrentSave();
	update();
	clickClock.restart();
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
		mousePress(window);

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

	

	saveBox.setPosition(sf::Vector2f(90, 490));
	saveBox.setSize(sf::Vector2f(235, 45));
	saveBox.setFillColor(sf::Color(0, 128, 0));

	saveText.setString("Save Modifiers");
	saveText.setFont(snakeFont);
	saveText.setPosition(sf::Vector2f(100, 500));
	saveText.setCharacterSize(20);
	saveText.setFillColor(sf::Color::Green);



	loadBox.setPosition(sf::Vector2f(320, 390));
	loadBox.setSize(sf::Vector2f(205, 65));
	loadBox.setFillColor(sf::Color::White);

	loadText.setString("Load Default\n  Modifiers");
	loadText.setFont(snakeFont);
	loadText.setPosition(sf::Vector2f(330, 400));
	loadText.setCharacterSize(20);
	loadText.setFillColor(sf::Color::Black);



	closeBox.setPosition(sf::Vector2f(540, 490));
	closeBox.setSize(sf::Vector2f(170, 65));
	closeBox.setFillColor(sf::Color(128, 0, 0));

	closeText.setString("Return To\nMain Menu");
	closeText.setFont(snakeFont);
	closeText.setPosition(550, 500);
	closeText.setCharacterSize(20);
	closeText.setFillColor(sf::Color::Red);
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

	window.draw(saveBox);
	window.draw(saveText);

	window.draw(loadBox);
	window.draw(loadText);

	window.draw(closeBox);
	window.draw(closeText);

	window.display();
}



Settings::eMousePositions Settings::getMousePosition(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	int x = mousePos.x;
	int y = mousePos.y;

	if (y >= 210 && y <= 275)
	{
		if (x >= 90 && x <= 315)
		{
			return elungCap;
		}

		if (x >= 490 && x <= 745)
		{
			return eWater;
		}
	}

	if (y >= 310 && y <= 375)
	{
		if (x >= 90 && x <= 350)
		{
			return eLungDec;
		}

		if (x >= 490 && x <= 745)
		{
			return eMove;
		}
	}

	if (y >= 390 && y <= 455)
	{
		if (x >= 320 && x <= 525)
		{
			return eLoad;
		}
	}

	if (y >= 490 && y <= 535)
	{
		if (x >= 90 && x <= 325)
		{
			return eSave;
		}
	}

	if (y >= 490 && y <= 555)
	{
		if (x >= 540 && x <= 710)
		{
			return eClose;
		}
	}

	return eNone;
}

void Settings::mousePress(sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clickClock.getElapsedTime().asSeconds() >= clickRate)
	{
		clickClock.restart();
		eMousePositions mousePos = getMousePosition(window);
		switch (mousePos)
		{
		case eMousePositions::elungCap:
			break;
		case eMousePositions::eLungDec:
			break;
		case eMousePositions::eWater:
			break;
		case eMousePositions::eMove:
			break;
		case eMousePositions::eSave:
			break;
		case eMousePositions::eLoad:
			break;
		case eMousePositions::eClose:
			break;
		default:
			break;
		}
	}
}

void Settings::restoreDefaults(void)
{
	std::ifstream input;
	input.open("default.txt");

	input >> lungCap >> lungDecrease >> waterCap >> moveSpeed;

	input.close();
}

void Settings::saveModifiers(void)
{
	std::ofstream output;
	output.open("savedMods.txt");
	if (output.fail())
	{
		std::cout << "File could not be loaded";
	}
	else
	{
		output << lungCap << "\t" << lungDecrease << "\t" << waterCap << "\t" << moveSpeed;
		output.close();
	}
}
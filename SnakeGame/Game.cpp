#include "Game.h"
#include "Player.h"
#include "Snake.h"

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

Game::Game(int lCapInput, int lCapDecreaseInput, int lCapIncreaseInput, int wCapInput, float speedInput)
{
	lungCapacity = lCapInput;
	capacityDecrease = lCapDecreaseInput;
	capacityIncrease = lCapIncreaseInput;
	
	waterCapacity = wCapInput;
	waterDrainRate = waterCapacity / 90;

	moveSpeed = speedInput;

	Player* player = new Player(1, lungCapacity);
	player1 = player;
}

void Game::checkDeath(sf::RenderWindow& window)
{
	if (player1->snakeHead->getX() <= 0 || player1->snakeHead->getX() >= 800)
	{
		player1->~Player();
		window.close();
	}
	if (player1->snakeHead->getY() <= 0 || player1->snakeHead->getY() >= 600)
	{
		player1->~Player();
		window.close();
	}
}

void Game::update()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GameWindow");
	while (window.isOpen())
	{
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

		draw(window);

		player1->setDirection();
		player1->move();
		sf::Time sleepTime = sf::seconds(moveSpeed);
		sf::sleep(sleepTime);
		
		checkDeath(window);
	}
}

void Game::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	player1->draw(window);

	window.display();
}

int Game::getLungCapacity(void)
{
	return lungCapacity;
}
int Game::getCapacityDecrease(void)
{
	return capacityDecrease;
}
int Game::getCapacityIncrease(void)
{
	return capacityIncrease;
}

int Game::getWaterCapacity(void)
{
	return waterCapacity;
}
float Game::getWaterDrainRate(void)
{
	return waterDrainRate;
}
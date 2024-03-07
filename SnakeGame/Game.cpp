#include "Game.h"
#include "Player.h"
#include "Snake.h"
#include "Food.h"

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
	clock = sf::Clock();
}

void Game::update()
{
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		Food* foodInitial = new Food(screenWidth, screenHeight, offset);
		food[i] = foodInitial;
	}

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

		foodCollision();

		player1->setDirection();
		sf::Time sleepTime = sf::seconds(moveSpeed);
		if (clock.getElapsedTime() >= sleepTime)
		{
			player1->move();
			clock.restart();
			snakeCollision(window);
		}

		checkOffscreen(window);

		player1->setSnakeCreated(false);
	}
}

void Game::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	player1->draw(window);

	for (int i = 0; i < 5; i++)
	{
		if (food[i]->getEaten() == false)
		{
			food[i]->draw(window);
		}
	}
	
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

void Game::checkOffscreen(sf::RenderWindow& window)
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

void Game::foodCollision(void)
{
	for (int i = 0; i < 5; i++)
	{
		if (food[i]-> getEaten() == false)
		{
			if (player1->snakeHead->getX() < (food[i]->getX() + 15) && player1->snakeHead->getX() > (food[i]->getX() - 15))
			{
				if (player1->snakeHead->getY() < (food[i]->getY() + 15) && player1->snakeHead->getY() > (food[i]->getY() - 15))
				{
					player1->setScore();
					food[i]->eat();
				}
			}
		}
	}
}

void Game::snakeCollision(sf::RenderWindow& window)
{
	if (player1->getSnakeCreated() == false)
	{
		int x = player1->snakeHead->getX();
		int y = player1->snakeHead->getY();

		Snake* sHead = player1->snakeHead;
		Snake* currentSnake = player1->snakeHead->nextSnake;
		while (currentSnake != nullptr)
		{
			if (sHead->getX() < (currentSnake->getX() + 15) && sHead->getX() > (currentSnake->getX() - 15))
			{
				if (sHead->getY() < (currentSnake->getY() + 15) && sHead->getY() > (currentSnake->getY() - 15))
				{
					player1->~Player();
					window.close();
					std::cout << "Collision detected";
				}
			}
			currentSnake = currentSnake->nextSnake;
		}
	}
}
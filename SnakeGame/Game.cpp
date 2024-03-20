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
	maxWaterCapacity = wCapInput;
	waterDrainRate = waterCapacity / 90;

	moveSpeed = speedInput;

	Player* player1st = new Player(1, lungCapacity);
	player1 = player1st;

	movementClock = sf::Clock();
	waterDrainClock = sf::Clock();
	respawnFoodClock = sf::Clock();
	foodRespawnRate = 1;

	deadSnake = false;
}

void Game::update()
{
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		Food* foodInitial = new Food(screenWidth, screenHeight, offset, waterCapacity);
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

		for (int i = 0; i < 5; i++)
		{
			food[i]->sink(waterCapacity, screenHeight);
		}

		player1->getInputs();
		sf::Time sleepTime = sf::seconds(moveSpeed);
		if (movementClock.getElapsedTime() >= sleepTime)
		{
			player1->move();
			movementClock.restart();
			snakeCollision(window);
			player1->breathe(screenHeight, waterCapacity, capacityDecrease);
		}

		if (player1->snakeHead == nullptr)
		{
			window.close();
			deadSnake = true;
		}

		if (deadSnake == false)
		{
			if (waterDrainClock.getElapsedTime() >= sf::seconds(1.0f))
			{
				waterCapacity -= waterDrainRate;
				waterDrainClock.restart();
			}

			if (waterCapacity == 0)
			{
				window.close();
			}

			if (waterCapacity > 60)
			{

				respawnFood();
			}

			checkOffscreen(window);

			player1->setSnakeCreated(false);
		}
	}
}

void Game::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	
	sf::RectangleShape water;
	water.setPosition(0, screenHeight - waterCapacity);
	water.setFillColor(sf::Color::Blue);
	water.setSize(sf::Vector2f(screenWidth, waterCapacity));
	window.draw(water);
	
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
	if (player1->snakeHead->getX() <= 0 || player1->snakeHead->getX() >= screenWidth)
	{
		player1->~Player();
		window.close();
	}
	if (player1->snakeHead->getY() <= 0 || player1->snakeHead->getY() >= screenHeight)
	{
		player1->~Player();
		window.close();
	}

	if (player1->snakeHead->getY() < (screenHeight - waterCapacity) - 20)
	{
		player1->sink();
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
					foodRespawnRate = (rand() % 7) + 3;
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

void Game::respawnFood(void)
{
	bool foodEaten = false;

	for (int i = 0; i < 5; i++)
	{
		if (food[i]->getEaten() == true)
		{
			foodEaten = true;
		}
	}

	if (respawnFoodClock.getElapsedTime() >= sf::seconds(foodRespawnRate) && foodEaten == true)
	{
		for (int i = 0; i < 5; i++)
		{
			if (food[i]->getEaten() == true)
			{
				food[i]->initialise(screenWidth, screenHeight, offset, waterCapacity);
				i = 5;
			}
		}

		foodRespawnRate = (rand() % 7) + 3;
		respawnFoodClock.restart();
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i != j)
			{
				if (food[i]->getX() == food[j]->getX())
				{
					if (food[i]->getY() == food[j]->getY())
					{
						food[j]->initialise(screenWidth, screenHeight, offset, waterCapacity);
					}
				}
			}
		}
	}
}
#include "Game.h"
#include "Player.h"
#include "Snake.h"
#include "Food.h"
#include "WinScreen.h"

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

Game::Game(int lCapInput, int lCapDecreaseInput, int wCapInput, float speedInput)
{
	lungCapacity = lCapInput;
	capacityDecrease = lCapDecreaseInput;
	
	waterCapacity = wCapInput;
	maxWaterCapacity = wCapInput;
	int waterDrainAmount = waterCapacity / 20;
	waterDrainRate = 90 / waterDrainAmount;
	std::cout << waterDrainRate << std::endl;

	moveSpeed = speedInput;

	Player* player1st = new Player(1, lungCapacity);
	player1 = player1st;

	Player* player2nd = new Player(2, lungCapacity);
	player2 = player2nd;

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

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "GameWindow");
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
		player2->getInputs();
		sf::Time sleepTime = sf::seconds(moveSpeed);
		if (movementClock.getElapsedTime() >= sleepTime)
		{
			player1->move();
			player2->move();
			movementClock.restart();

			snakeCollision(window);

			player1->breathe(screenHeight, waterCapacity, capacityDecrease);
			player2->breathe(screenHeight, waterCapacity, capacityDecrease);
		}

		if (player1->snakeHead == nullptr)
		{
			window.close();
			deadSnake = true;
			WinScreen winscreen = WinScreen(2, player2->getScore());
		}

		if (player2->snakeHead == nullptr)
		{
			window.close();
			deadSnake = true;
			WinScreen winscreen = WinScreen(1, player1->getScore());
		}

		if (deadSnake == false)
		{
			if (waterDrainClock.getElapsedTime() >= sf::seconds(waterDrainRate))
			{
				waterCapacity -= 20;
				waterDrainClock.restart();
			}

			if (waterCapacity == 0)
			{
				window.close();
				
				if (player1->getScore() == player2->getScore())
				{
					WinScreen(0, player1->getScore());
				}

				else if (player1->getScore() < player2->getScore())
				{
					WinScreen(1, player1->getScore());
				}
				else if (player1->getScore() > player2->getScore())
				{
					WinScreen(2, player2->getScore());
				}
			}

			if (waterCapacity > 60)
			{
				respawnFood();
			}

			checkOffscreen(window);

			player1->setSnakeCreated(false);
			player2->setSnakeCreated(false);
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

	player2->draw(window);

	for (int i = 0; i < 5; i++)
	{
		if (food[i]->getEaten() == false)
		{
			food[i]->draw(window);
		}
	}

	window.display();
}

void Game::checkOffscreen(sf::RenderWindow& window)
{
	//Player 1 check
	if (player1->snakeHead->getX() <= 0 || player1->snakeHead->getX() >= screenWidth)
	{
		player1->~Player();
		window.close();
		WinScreen winscreen = WinScreen(2, player2->getScore());
	}
	if (player1->snakeHead->getY() <= 0 || player1->snakeHead->getY() >= screenHeight)
	{
		player1->~Player();
		window.close();
		WinScreen winscreen = WinScreen(2, player2->getScore());
	}
	if (player1->snakeHead->getY() < (screenHeight - waterCapacity) - 20)
	{
		player1->snakeHead->sink();
	}

	if (player2->snakeHead->getX() <= 0 || player2->snakeHead->getX() >= screenWidth)
	{
		player2->~Player();
		window.close();
		WinScreen winscreen = WinScreen(1, player1->getScore());
	}
	if (player2->snakeHead->getY() <= 0 || player2->snakeHead->getY() >= screenHeight)
	{
		player2->~Player();
		window.close();
		WinScreen winscreen = WinScreen(1, player1->getScore());
	}

	if (player2->snakeHead->getY() < (screenHeight - waterCapacity) - 20)
	{
		player2->snakeHead->sink();
	}
}

void Game::foodCollision(void)
{
	for (int i = 0; i < 5; i++)
	{
		if (food[i]->getEaten() == false)
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

			if (player2->snakeHead->getX() < (food[i]->getX() + 15) && player2->snakeHead->getX() > (food[i]->getX() - 15))
			{
				if (player2->snakeHead->getY() < (food[i]->getY() + 15) && player2->snakeHead->getY() > (food[i]->getY() - 15))
				{
					player2->setScore();
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
					WinScreen winscreen = WinScreen(2, player2->getScore());
				}
			}
			currentSnake = currentSnake->nextSnake;
		}

		currentSnake = player2->snakeHead->nextSnake;
		while (currentSnake != nullptr)
		{
			if (sHead->getX() < (currentSnake->getX() + 15) && sHead->getX() > (currentSnake->getX() - 15))
			{
				if (sHead->getY() < (currentSnake->getY() + 15) && sHead->getY() > (currentSnake->getY() - 15))
				{
					player2->~Player();
					window.close();
					std::cout << "Collision detected";
					WinScreen winscreen = WinScreen(2, player2->getScore());
				}
			}
			currentSnake = currentSnake->nextSnake;
		}
	}

	if (player2->getSnakeCreated() == false)
	{
		int x = player2->snakeHead->getX();
		int y = player2->snakeHead->getY();

		Snake* sHead = player2->snakeHead;
		Snake* currentSnake = player2->snakeHead->nextSnake;
		while (currentSnake != nullptr)
		{
			if (sHead->getX() < (currentSnake->getX() + 15) && sHead->getX() > (currentSnake->getX() - 15))
			{
				if (sHead->getY() < (currentSnake->getY() + 15) && sHead->getY() > (currentSnake->getY() - 15))
				{
					player2->~Player();
					window.close();
					std::cout << "Collision detected";
					WinScreen winscreen = WinScreen(1, player1->getScore());
				}
			}
			currentSnake = currentSnake->nextSnake;
		}

		currentSnake = player1->snakeHead;
		if(sHead->getX() < (currentSnake->getX() + 15) && sHead->getX() > (currentSnake->getX() - 15))
		{
			if (sHead->getY() < (currentSnake->getY() + 15) && sHead->getY() > (currentSnake->getY() - 15))
			{
				player1->~Player();
				player2->~Player();
				window.close();
				std::cout << "Head on collision detected";
				WinScreen winscreen = WinScreen(0, player1->getScore());
			}
		}

		currentSnake = player1->snakeHead->nextSnake;
		while (currentSnake != nullptr)
		{
			if (sHead->getX() < (currentSnake->getX() + 15) && sHead->getX() > (currentSnake->getX() - 15))
			{
				if (sHead->getY() < (currentSnake->getY() + 15) && sHead->getY() > (currentSnake->getY() - 15))
				{
					player2->~Player();
					window.close();
					std::cout << "Collision detected";
					WinScreen winscreen = WinScreen(1, player1->getScore());

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

		foodRespawnRate = (rand() % 3) + 3;
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
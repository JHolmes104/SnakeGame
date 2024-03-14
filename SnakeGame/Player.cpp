#include "Player.h"
#include "Snake.h"
#include "LungBar.h"

#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player()
{

}

Player::Player(int playerNumberInput, int maxCapacityInput)
{
	playerNumber = playerNumberInput;
	currentLungCapacity = maxCapacityInput;
	maxLungCapacity = maxCapacityInput;
	Snake* snake = new Snake(100, 100, playerNumberInput);
	snakeHead = snake;
	size = 1;
	direction = 1;

	LungBar* newBar = new LungBar(maxCapacityInput, playerNumberInput);
	lungbar = newBar;
}

Player::~Player()
{
	snakeHead->~Snake();
}

void Player::setDirection()
{
	// 1 = Up, 2 = Right, 3 = Down, 4 = Left.
	if (playerNumber == 1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && direction != 3)
		{
			direction = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && direction != 4)
		{
			direction = 2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && direction != 1)
		{
			direction = 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && direction != 2)
		{
			direction = 4;
		}
	}

	else if (playerNumber == 2)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != 3)
		{
			direction = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != 4)
		{
			direction = 2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != 1)
		{
			direction = 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != 2)
		{
			direction = 4;
		}
	}
}

void Player::move(void)
{
	snakeHead->shiftSnakes(snakeHead->getX(), snakeHead->getY());
	switch (direction)
	{
	case 1:
		snakeHead->setY(-20);
		break;
	case 2:
		snakeHead->setX(20);
		break;
	case 3:
		snakeHead->setY(20);
		break;
	case 4:
		snakeHead->setX(-20);
		break;
	default:
		break;
	}
}

int Player::getSize(void)
{
	return size;
}

void Player::draw(sf::RenderWindow& window)
{
	lungbar->draw(window);
	snakeHead->draw(window);
}

int Player::getScore(void)
{
	return score;
}

void Player::setScore(void)
{
	score++;
	size++;
	Snake* nextSnake = new Snake(snakeHead->getX(), snakeHead->getY(), playerNumber);
	snakeHead->setNextSnake(nextSnake);
	snakeCreated = true;
}

bool Player::getSnakeCreated(void)
{
	return snakeCreated;
}

void Player::setSnakeCreated(bool newSC)
{
	snakeCreated = newSC;
}

void Player::breathe(int screenHeight, int waterCapacity, int drainRate)
{
	if ((screenHeight - waterCapacity) > snakeHead->getY())
	{
		currentLungCapacity += (4 * drainRate);
		if (currentLungCapacity > maxLungCapacity)
		{
			currentLungCapacity = maxLungCapacity;
		}
	}
	else
	{

		currentLungCapacity -= drainRate;
		if (currentLungCapacity <= 0)
		{
			std::cout << "Minimimum capacity" << std::endl;
			currentLungCapacity = 0;
			removeEnd();
		}
	}
	lungbar->updateCapacity(currentLungCapacity);
}

void Player::removeEnd(void)
{
	if (snakeHead->nextSnake != nullptr)
	{
		std::cout << "Removing" << std::endl;
		snakeHead->removeEnd();
	}
	else
	{
		snakeHead->~Snake();
		snakeHead = nullptr;
	}
}
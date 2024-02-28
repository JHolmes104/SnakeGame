#include "Player.h"
#include <SFML/Graphics.hpp>


Player::Player()
{

}

Player::Player(int playerNumberInput, Game* thisGame)
{
	playerNumber = playerNumberInput;
	currentGame = thisGame;
	currentLungCapacity = currentGame->getLungCapacity();
	Snake snake = Snake(100, 100, 1);
	direction = 1;
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

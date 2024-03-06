#pragma once
#include <SFML/Graphics.hpp>

class Food;
class Player;

int constexpr screenWidth = 800;
int constexpr screenHeight = 600;
int constexpr offset = 20;

class Game
{
private:
	Food* food[5];

	int lungCapacity;
	int capacityDecrease;
	int capacityIncrease;
	
	int waterCapacity;
	float waterDrainRate;

	float moveSpeed;

	Player* player1;

	sf::Window window;

public:
	Game();
	Game(int lCapInput, int lCapDecreaseInput, int lCapIncreaseInput, int wCapInput, float speedInput);

	void update(void);

	void draw(sf::RenderWindow& window);
	
	int getLungCapacity(void);
	int getCapacityDecrease(void);
	int getCapacityIncrease(void);

	int getWaterCapacity(void);
	float getWaterDrainRate(void);

	void checkDeath(sf::RenderWindow& window);
	void foodCollision(void);
};


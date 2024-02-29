#pragma once
#include <SFML/Graphics.hpp>

class Player;

class Game
{
private:
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

	void update();
	
	int getLungCapacity(void);
	int getCapacityDecrease(void);
	int getCapacityIncrease(void);

	int getWaterCapacity(void);
	float getWaterDrainRate(void);

	void updateTrial(void);

	void checkDeath(sf::RenderWindow& window);
};


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

	sf::Clock movementClock;
	sf::Clock waterDrainClock;
	sf::Clock respawnFoodClock;

	int lungCapacity;
	int capacityDecrease;
	int capacityIncrease;
	
	int waterCapacity;
	int maxWaterCapacity;
	float waterDrainRate;

	float moveSpeed;

	int foodRespawnRate;

	Player* player1;

	sf::Window window;

public:
	Game();
	Game(int lCapInput, int lCapDecreaseInput, int lCapIncreaseInput, int wCapInput, float speedInput);

	void update(void);

	void draw(sf::RenderWindow& window);
	
	void respawnFood(void);

	int getLungCapacity(void);
	int getCapacityDecrease(void);
	int getCapacityIncrease(void);

	int getWaterCapacity(void);
	float getWaterDrainRate(void);

	void checkOffscreen(sf::RenderWindow& window);
	void foodCollision(void);
	void snakeCollision(sf::RenderWindow& window);
};


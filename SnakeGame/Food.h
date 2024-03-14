#pragma once
#include <SFML/Graphics.hpp>
class Food
{
private:
	int x;
	int y;
	bool eaten;
public:
	Food(void);
	Food(int screenWidth, int screenHeight, int offset, int waterCapacity);

	~Food(void);

	void draw(sf::RenderWindow& window);
	
	void initialise(int screenWidth, int screenHeight, int offset, int waterCapacity);

	int getX(void);
	int getY(void);
	bool getEaten(void);

	void eat(void);
	void sink(int waterCapacity, int screenHeight);
};


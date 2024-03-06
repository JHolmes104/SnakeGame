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
	Food(int screenWidth, int screenHeight, int offset);

	~Food(void);

	void draw(sf::RenderWindow& window);
	
	int getX(void);
	int getY(void);
	bool getEaten(void);

	void eat(void);
};


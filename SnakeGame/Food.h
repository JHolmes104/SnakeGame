#pragma once
#include <SFML/Graphics.hpp>
class Food
{
private:
	int x;
	int y;
public:
	Food();

	void draw(sf::RenderWindow& window);
	int getX(void);
	int getY(void);
};


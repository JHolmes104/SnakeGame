#pragma once
#include <SFML/Graphics.hpp>

class MainMenu
{
private:
	void startGame(void);

	void draw(sf::RenderWindow& window);

	void mouseInputs(sf::RenderWindow& window);

	void setGameStats(void);

	void initialiseShapes(void);

	sf::Font snakeFont;
	sf::Text titleText;
	sf::Text gameText;
	sf::RectangleShape gameBox;

	int lungCap;
	int lungDecrease;
	int waterCap;
	float moveSpeed;

	void loadModifiers(void);

public:
	MainMenu(void);
	void update(void);
};


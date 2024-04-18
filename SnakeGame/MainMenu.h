#pragma once
#include <SFML/Graphics.hpp>

int constexpr minStartX = 200;
int constexpr maxStartX = 300;

int constexpr minStartY = 200;
int constexpr maxStartY = 600;

int constexpr minExitX = 200;
int constexpr maxExitX = 600;

int constexpr minExitY = 400;
int constexpr maxExitY = 500;

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

public:
	MainMenu(void);
	void update(void);
};


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

int constexpr screenWidth = 800;
int constexpr screenHeight = 600;

class MainMenu
{
private:
	void startGame(void);
	void closeGame(void);

	void draw(sf::RenderWindow& window);

	void getInputs(void);

public:
	MainMenu(void);
	void update(void);
};


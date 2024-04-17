#include "MainMenu.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

MainMenu::MainMenu()
{
	update();
}

void MainMenu::update()
{
	sf::RenderWindow window(sf::VideoMode(800,600), "Main Menu");
	while (window.isOpen())
	{ 
		window.clear(sf::Color::Black);
		window.display();
	}
}
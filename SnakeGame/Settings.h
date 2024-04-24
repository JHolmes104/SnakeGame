#pragma once
#include <SFML/Graphics.hpp>
class Settings
{
private:
	void saveModifiers(void);
	void restoreDefaults(void);
	void returnToMainMenu(void);
	void loadCurrentSave(void);

	int lungCap;
	int lungDecrease;
	int waterCap;
	float moveSpeed;

	void changeLungCap(void);
	void changeLungDec(void);
	void changeWaterCap(void);
	void changeMoveSpeed(void);

	sf::Font snakeFont;
	sf::Text titleText;

	sf::Text lungCapText;
	sf::Text lungDecText;
	sf::Text waterText;
	sf::Text moveText;

	sf::RectangleShape lungCapBox;
	sf::RectangleShape lungDecBox;
	sf::RectangleShape waterBox;
	sf::RectangleShape moveBox;

	void update(void);
	void initialiseShapes(void);
	void draw(sf::RenderWindow& window);
	void mouseInputs(sf::RenderWindow& window);
public:
	Settings(void);
};
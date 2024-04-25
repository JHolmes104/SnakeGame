#pragma once
#include <SFML/Graphics.hpp>
class Settings
{
private:

	enum eMousePositions
	{
		eNone,
		elungCap,
		eLungDec,
		eWater,
		eMove,
		eSave,
		eLoad,
		eClose
	};

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
	sf::Text saveText;
	sf::Text loadText;
	sf::Text closeText;

	sf::RectangleShape lungCapBox;
	sf::RectangleShape lungDecBox;
	sf::RectangleShape waterBox;
	sf::RectangleShape moveBox;
	sf::RectangleShape saveBox;
	sf::RectangleShape loadBox;
	sf::RectangleShape closeBox;

	void update(void);
	void initialiseShapes(void);
	void draw(sf::RenderWindow& window);

	eMousePositions getMousePosition(sf::RenderWindow& window);
	void mousePress(sf::RenderWindow& window);

	void restoreDefaults(void);
	void saveModifiers(void);
public:
	Settings(void);
};
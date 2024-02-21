/*
  Games Software Engineering GAD1006-N
  Snake ICA start project 
  
  Project set up to use SFML
  SFML documentation: https://www.sfml-dev.org/learn.php
*/

#include <iostream>

// SFML header file for graphics, there are also ones for Audio, Window, System and Network
#include <SFML/Graphics.hpp>

int main()
{
    // All SFML types and functions are contained in the sf namespace

    // TODO: 
    // Create an instance of the SFML RenderWindow type which represents the display
    // and initialise its size and title text    
    sf::RenderWindow window(sf::VideoMode(800, 600), "MyWindow");

    // We can still output to the console window
    std::cout << "SnakeGame: Starting" << std::endl;

    // TODO:
    // Make a main loop that continues until we call window.close()  
    // 
    // {
        // Inside the lopp:
        // Poll for events from the window and handle the closed one  
        // Clear the window to a colour
        // Display the window contents
    // }

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(80, 80));
    rectangle.setOutlineThickness(20);
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setOutlineColor(sf::Color::Magenta);
    rectangle.setOutlineThickness(20);
    rectangle.setPosition(145, 145);

    sf::CircleShape circle;
    circle.setRadius(85);
    circle.setOutlineThickness(10);
    circle.setPosition(100 , 100);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::White);

    sf::ConvexShape pentagon;
    pentagon.setPointCount(5);
    pentagon.setPoint(0, sf::Vector2f(185, 500));
    pentagon.setPoint(1, sf::Vector2f(50, 300));
    pentagon.setPoint(4, sf::Vector2f(320, 300));
    pentagon.setPoint(2, sf::Vector2f(50, 50));
    pentagon.setPoint(3, sf::Vector2f(320, 65));
    pentagon.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        window.pollEvent(event);
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }

        window.clear(sf::Color::Black);
        window.draw(pentagon);
        window.draw(pentagon);
        window.draw(circle);
        window.draw(rectangle);

        window.display();
    }

    std::cout << "SnakeGame: Finished" << std::endl;

    return 0;
}

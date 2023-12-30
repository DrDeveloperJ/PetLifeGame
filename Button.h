#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
private:
    sf::RectangleShape button;
    sf::Texture ButtonTexture;
    sf::Texture OnButtonTexture;
    sf::Sprite Sprite;

public:
    Button();
    void MouseOver(sf::RenderWindow& window);                                                   // Checks if the mouse is over the button and changes the state accordingly
    void setPosition(sf::Vector2f Position);						                            // Sets the position of the button
    void switchState(int state);									                            // Switches the state of the button
    void setTexture(int indexX, int indexY, int sizeX, int sizeY);	                            // Sets the texture of the button
    void updateButtonTexture(sf::Texture& texture, sf::Texture& ontTexture);					// Updates the texture of the button
    void DrawTo(sf::RenderWindow& window);							                            // Draws the button to the window
    void Load(std::string dir, std::string OnDir, sf::Vector2f Size, int NoPressindexX, int NoPressindexY, int NoPressSizeX, int NoPressSizeY);
    
    int ButtonState = 0;
    bool active = true;
};
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
public:
    Button();
    void MouseOver(sf::RenderWindow& window);
    void setPosition(sf::Vector2f Position);
    void switchState(int state);
    void setTexture(int indexX, int indexY, int sizeX, int sizeY);
    void DrawTo(sf::RenderWindow& window);
    void Load(std::string dir, std::string OnDir, sf::Vector2f Size, int NoPressindexX, int NoPressindexY, int NoPressSizeX, int NoPressSizeY);
    int ButtonState = 0;
    bool active = true;

private:
    sf::RectangleShape button;
    sf::Texture ButtonTexture;
    sf::Texture OnButtonTexture;
    sf::Sprite Sprite;
};
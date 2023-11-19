#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
public:
    Button();
    bool isMouseOver(sf::RenderWindow& window);
    void setPosition(sf::Vector2f Position);
    void switchState(int state);
    void DrawTo(sf::RenderWindow& window);
    void Load(std::string dir, std::string OnDir, sf::Vector2f Size);

private:
    sf::RectangleShape button;
    sf::Texture ButtonTexture;
    sf::Texture OnButtonTexture;
    sf::Sprite Sprite;
};
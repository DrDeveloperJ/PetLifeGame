#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
public:
    Button();
    bool isMouseOver(sf::RenderWindow& window);
    void setPosition(sf::Vector2f Position);
    void setFont(sf::Font &Font);
    void setBackColor(sf::Color Color);
    void DrawTo(sf::RenderWindow& window);
    void Initialize(std::string Text, sf::Vector2f Size, int charSize, sf::Color bgColor, sf::Color textColor);
    void Hide();

private:
    sf::RectangleShape button;
    sf::Text text;
};
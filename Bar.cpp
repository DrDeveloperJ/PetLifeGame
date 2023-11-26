#include "Bar.h"
#include <iostream>
#include <cmath>

Bar::Bar()
{
}

Bar::~Bar()
{
}

void Bar::Load(std::string dir)
{
    if (barTexture.loadFromFile(dir))
    {
        std::cout << "Loaded Bar Texture" << std::endl;
        Sprite.setTexture(barTexture);
    }
    else
    {
        std::cout << "Failed to load Bar Texture" << std::endl;
    }
}

void Bar::Load(std::string dir, int indexX, int indexY, int sizeX, int sizeY)
{
    if (barTexture.loadFromFile(dir))
    {
        std::cout << "Loaded Bar Texture" << std::endl;
        Sprite.setTexture(barTexture);
        Sprite.setTextureRect(sf::Rect(indexX, indexY, sizeX, sizeY));
    }
    else
    {
        std::cout << "Failed to load Bar Texture" << std::endl;
    }
}

void Bar::setTexture(int indexX, int indexY, int sizeX, int sizeY)
{
	Sprite.setTextureRect(sf::Rect(indexX, indexY, sizeX, sizeY));
}

void Bar::Initialize(int givenValue, const sf::Vector2f Scale, sf::Font& font)
{
    value = givenValue;
    displayedValue.setFont(font);
    displayedValue.setString(std::to_string(value));
    displayedValue.setFillColor(sf::Color::White);
    Sprite.setScale(Scale);
}

void Bar::Initialize(int givenValue, const sf::Vector2f Scale)
{
    value = givenValue;
    Sprite.setScale(Scale);
}

void Bar::updateValue(int newvalue)
{
    value = newvalue;
    displayedValue.setString(std::to_string(value));
}

void Bar::setPosition(const sf::Vector2f Position, const sf::Vector2f PositionText)
{
    Sprite.setPosition(Position);
    displayedValue.setPosition(PositionText);
}

void Bar::setPosition(const sf::Vector2f Position)
{
    Sprite.setPosition(Position);
}

void Bar::DrawTo(sf::RenderWindow& window)
{
    window.draw(Sprite);
    window.draw(displayedValue);
}

void Bar::DrawSpriteOnlyTo(sf::RenderWindow& window)
{
    window.draw(Sprite);
}

void Bar::DecrementValue(int amount, float &gameTime, float timeBetweenSwitch)
{
    if ((gameTime >= timeBetweenSwitch) && (empty == false))
    {
        value -= amount;
        if (value == 0)
        {
			empty = true;
		}
        std::cout << "New Value = " << value << std::endl;

        currentX += 200;

        setTexture(currentX, 0, 200, 100);
    }
}

void Bar::IncrementValue(int amount, float& gameTime, float timeBetweenSwitch)
{
    if (gameTime >= timeBetweenSwitch)
    {
        value += amount;
        std::cout << "New Value = " << value << std::endl;

        if (currentX == 1200)
        {
            currentX = 0;
        }
        else
        {
            currentX += 200;
        }

        setTexture(currentX, 0, 200, 100);
    }
}
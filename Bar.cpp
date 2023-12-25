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
    // Loads the bar texture for bars which will not change such as the currency bar
    // (The value will change but the bar background will not)
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
    // Loads the bar texture for bars which will change such as the hunger bar, or boredom bar for example
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
    // Sets the texture of the bar (Used for changing the bar texture state for example when the hunger bar goes down)
    Sprite.setTextureRect(sf::Rect(indexX, indexY, sizeX, sizeY));
}

void Bar::Initialize(int givenValue, const sf::Vector2f Scale, sf::Font& font)
{
    // Initializes the bar (Currency Bar)
    value = givenValue;
    displayedValue.setFont(font);
    displayedValue.setString(std::to_string(value));
    displayedValue.setFillColor(sf::Color::White);
    Sprite.setScale(Scale);
}

void Bar::Initialize(bool empty, bool full, int givenValue, const sf::Vector2f Scale)
{
    // Initializes the bar (Hunger, Energy, Bath and Boredom Bar)
    value = givenValue;
    Sprite.setScale(Scale);

    // Sets the bar to the correct starting texture depending on if it is full or empty
    if (full == true)
    {
        currentX = 0;
    }
    else
    {
        currentX = 1200;
    }
}

void Bar::updateValue(int newvalue)
{
    // Updates the value of the bar
    value = newvalue;
    displayedValue.setString(std::to_string(value));
}

int Bar::getValue()
{
    // Returns the value of the bar
    return value;
}

void Bar::resetValue()
{
    // Resets the value of the bar
    value = 0;
    full = false;
    empty = true;
}

void Bar::setCurrentX(int currentXNew)
{
    // Sets the current X position of the bar
    currentX = currentXNew;
}

void Bar::setPosition(const sf::Vector2f Position, const sf::Vector2f PositionText)
{
    // Sets the position of the bar and the text (Currency Bar)
    Sprite.setPosition(Position);
    displayedValue.setPosition(PositionText);
}

void Bar::setPosition(const sf::Vector2f Position)
{
    // Sets the position of the bar
    Sprite.setPosition(Position);
}

void Bar::DrawTo(sf::RenderWindow& window)
{
    // Renders the bar and the text (Currency Bar)
    window.draw(Sprite);
    window.draw(displayedValue);
}

void Bar::DrawSpriteOnlyTo(sf::RenderWindow& window)
{
    // Renders the bar (Hunger, Energy, Bath and Boredom Bar)
    window.draw(Sprite);
}

void Bar::DecrementValue(int amount, float& gameTime, float timeBetweenSwitch)
{
    // Decrements the value of the bar based on a timer
    if ((gameTime >= timeBetweenSwitch) && (empty == false))
    {
        value -= amount;

        // Checks if the bar is empty or full
        if (value == 0)
        {
            empty = true;
        }
		else
		{
			empty = false;
		}
        if (value == 6)
        {
            full = true;
        }
        else
        {
            full = false;
        }

        std::cout << "New Value = " << value << std::endl;

        // Changes the texture of the bar depending on the value
        currentX += 200;
        setTexture(currentX, 0, 200, 100);
    }
}

void Bar::IncrementValue(int amount, float& gameTime, float timeBetweenSwitch)
{
    // Increments the value of the bar based on a timer
    if ((gameTime >= timeBetweenSwitch) && (full == false))
    {
        value += amount;

        // Checks if the bar is empty or full
        if (value == 0)
        {
            empty = true;
        }
        else
        {
            empty = false;
        }
        if (value == 6)
        {
            full = true;
        }
		else
		{
			full = false;
		}

        std::cout << "New Value = " << value << std::endl;

        // Changes the texture of the bar depending on the value
        currentX -= 200;
        setTexture(currentX, 0, 200, 100);
    }
}

void Bar::IncrementValue(int amount)
{
    // Increments the value of the bar
    if (full == false)
    {
        value += amount;

        if (value == 0)
        {
            empty = true;
        }
        else
        {
            empty = false;
        }
        if (value == 6)
        {
            full = true;
        }
        else
        {
            full = false;
        }

        std::cout << "New Value = " << value << std::endl;

        // Changes the texture of the bar depending on the value
        currentX -= 200;
        setTexture(currentX, 0, 200, 100);
    }
}

void Bar::DecrementHealthValue(int amount, float& gameTime, float timeBetweenSwitch)
{
    // Decrements the value of the Health Heart based on a timer
    if ((gameTime >= timeBetweenSwitch) && (empty == false))
    {
        value -= amount;
        std::cout << "New Health Value = " << value << std::endl;

        if (value == 0)
        {
            empty = true;
        }

        // Changes the texture of the Health Heart depending on the value
        currentX += 17;
        setTexture(currentX, 0, 17, 17);
    }
}
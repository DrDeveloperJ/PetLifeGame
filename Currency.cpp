#include "Currency.h"
#include <iostream>

void Currency::Load(std::string dir)
{
    // Loads the texture and sets the sprite
    if (currencyTexture.loadFromFile(dir))
    {
        std::cout << "Loaded CurrencyAnimation Texture" << std::endl;
    }
    else
    {
        std::cout << "Failed to load CurrencyAnimation Texture" << std::endl;
    }

    currencySprite.setTexture(currencyTexture);
    currencySprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

void Currency::draw(sf::RenderWindow& window)
{
    // Draws the currency
	window.draw(currencySprite);
}

void Currency::initialize(sf::Vector2f position)
{
    // Initializes the currency
    currencySprite.setPosition(position);
    currencySprite.setScale({ 4, 4 });
}

void Currency::setActive(bool newactive)
{
    // Sets the currency to active or inactive
	active = newactive;
}

bool Currency::getActive()
{
	// Returns if the currency is active or not
	return active;
}

void Currency::AnimationUpdate(float deltaTime, float timeBetweenSwitch)
{
    // Updates the animation of the currency to show the next frame
    interval += deltaTime;
    if (interval >= timeBetweenSwitch) // If the interval is greater than or equal to the defined time between switch, reset the interval and run the next texture in the animation
    {
        interval = 0.0f; // Resets the interval
        if (currentAnimationStage == 128)
        {
            currentAnimationStage = 0;
            currencySprite.setTextureRect(sf::IntRect(currentAnimationStage, 0, 16, 16));
            active = false;
        }
        else
        {
            currentAnimationStage += 16;
            currencySprite.setTextureRect(sf::IntRect(currentAnimationStage, 0, 16, 16));
        }
    }
}

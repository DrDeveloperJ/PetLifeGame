#include "Player.h"
#include <iostream>

void Player::Initialize()
{
    Sprite.scale(sf::Vector2f(0.75, 0.75)); // Scales the player
    movementAllow = true; // Allows the player to move
    Sprite.setPosition({ 475, 290 }); // Sets the player's position
}

void Player::setTexture(int xindex, int yindex)
{
    Sprite.setTexture(playerTexture); // Sets the texture for the player
    Sprite.setTextureRect(sf::IntRect(xindex, yindex, 542, 474)); // Sets the texture rectangle for the player
}

void Player::Load(std::string dir)
{
    if (playerTexture.loadFromFile(dir))
    {
        std::cout << "Loaded Player Texture" << std::endl;
        //Sprite.setTexture(playerTexture);
        //Sprite.setTextureRect(sf::IntRect(xindex, yindex, 45, 72));
    }
    else
    {
        std::cout << "Failed to load Player Texture" << std::endl;
    }
}

void Player::Update()
{
    // Allows the player to move
    if (movementAllow == true)
    {
        sf::Vector2f position = Sprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            Sprite.setPosition(position + sf::Vector2f(1, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            Sprite.setPosition(position + sf::Vector2f(0, 1));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            Sprite.setPosition(position + sf::Vector2f(-1, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            Sprite.setPosition(position + sf::Vector2f(0, -1));
        }
    }
}

void Player::AnimationUpdate(int row, float deltaTime, float timeBetweenSwitch)
{
    interval += deltaTime;
    if (interval >= timeBetweenSwitch) // If the interval is greater than or equal to the defined time between switch, reset the interval and run the next texture in the animation
    {
        interval = 0.0f; // Resets the interval

        if (currentAnimationStage == 4878)
        {
            currentAnimationStage = 0;
            setTexture(currentAnimationStage, row);
        }
        else
        {
            currentAnimationStage += 542;
            setTexture(currentAnimationStage, row);
        }
	}
}

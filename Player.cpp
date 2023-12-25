#include "Player.h"
#include <iostream>

void Player::Initialize()
{
    Sprite.scale(sf::Vector2f(0.75, 0.75));                             // Scales the player
    movementAllow = true;                                               // Allows the player to move
    Sprite.setPosition({ 475, 290 });                                   // Sets the player's position
}

void Player::setTexture(int xindex, int yindex)
{
    Sprite.setTexture(playerTexture);                                   // Sets the texture for the player
    Sprite.setTextureRect(sf::IntRect(xindex, yindex, 542, 474));       // Sets the texture rectangle for the player
}

void Player::setTexture(int xindex, int yindex, int width, int height)
{
	Sprite.setTexture(playerTexture);                                   // Sets the texture for the player
	Sprite.setTextureRect(sf::IntRect(xindex, yindex, width, height));  // Sets the texture rectangle for the player
}

void Player::Load(std::string dir)
{
    // Loads the texture for the player
    if (playerTexture.loadFromFile(dir))
    {
        std::cout << "Loaded Player Texture" << std::endl;
    }
    else
    {
        std::cout << "Failed to load Player Texture" << std::endl;
    }
}

void Player::AnimationUpdate(int row, float deltaTime, float timeBetweenSwitch)
// Plays the current chosen animation for the player
{
    interval += deltaTime;

    // If the interval is greater than or equal to the defined time between switch, reset the interval and run the next texture in the animation
    if (interval >= timeBetweenSwitch)
    {
        interval = 0.0f; // Resets the interval
        if (row == 948 || row == 1896 || row == 2370)
        {
            if (previousRow != row)
            {
                previousRow = row;
                currentAnimationStage = 0;
            }

            if (currentAnimationStage == 3794)
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
        else
        {
            if (row == 3318)
            {
                if (previousRow != row)
                {
                    previousRow = row;
                    currentAnimationStage = 556;
                }

                if (currentAnimationStage < 5004)
                {
                    currentAnimationStage += 556;
                    setTexture(currentAnimationStage, row, 556, 504);
                }
            }
            else
            {
                if (previousRow != row)
                {
                    previousRow = row;
                    currentAnimationStage = 0;
                }

                if (currentAnimationStage >= 4878)
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
    }
}

#include "Player.h"
#include <iostream>

void Player::Initialize()
{
    Sprite.scale(sf::Vector2f(6, 6));
    movementAllow = true;
    Sprite.setPosition({ 525, 255 });
}

void Player::setTexture(int xindex, int yindex)
{
    Sprite.setTexture(playerTexture);
    Sprite.setTextureRect(sf::IntRect(xindex, yindex, 45, 72));
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

#include "TitleScreen.h"
#include <iostream>

TitleScreen::TitleScreen()
{
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::Load(std::string Dir)
{
    // Load the texture from the directory and set the sprite to the texture
    if (TitleTexture.loadFromFile(Dir))
    {
        std::cout << "Loaded Title Texture" << std::endl;
        Sprite.setTexture(TitleTexture);
        Sprite.setTextureRect(sf::IntRect(0, 0, 600, 200));
        Sprite.setPosition({ 375, 75 });
    }
    else
    {
        std::cout << "Failed to load Title Texture" << std::endl;
    }
}

void TitleScreen::setPosition(const sf::Vector2f Position)
{
    // Set the position of the sprite
    Sprite.setPosition(Position);
}


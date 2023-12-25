#include "Debuff.h"
#include <iostream>

Debuff::Debuff()
{
}

Debuff::~Debuff()
{
}

void Debuff::Load(std::string dir, sf::Vector2f Scale)
{
	// Load the texture and set the sprite
	if (DebuffTexture.loadFromFile(dir))
	{
		std::cout << "Loaded Debuff Texture" << std::endl;
		Sprite.setTexture(DebuffTexture);
	}
	else
	{
		std::cout << "Failed to load Debuff Texture" << std::endl;
	}

	Sprite.setScale(Scale);
}

void Debuff::Initialize(float newchange)
{
	// Set the change
	change = newchange;
}

void Debuff::setPosition(sf::Vector2f position)
{
	// Set the position
	Sprite.setPosition(position);
}

void Debuff::setActive(bool newactive)
{
	// Set the active
	active = newactive;
}

bool Debuff::getActive()
{
	// Return active
	return active;
}

void Debuff::DrawTo(sf::RenderWindow& window)
{
	// Draw the sprite
	window.draw(Sprite);
}

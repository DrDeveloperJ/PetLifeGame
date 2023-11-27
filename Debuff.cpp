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
	change = newchange;
}

void Debuff::setPosition(sf::Vector2f position)
{
	Sprite.setPosition(position);
}

void Debuff::setActive(bool newactive)
{
	active = newactive;
}

bool Debuff::getActive()
{
	switch (active)
	{
		case true:
			return true;
		case false:
			return false;
	}
}

void Debuff::DrawTo(sf::RenderWindow& window)
{
	window.draw(Sprite);
}

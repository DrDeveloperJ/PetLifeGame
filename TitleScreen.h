#pragma once
#include <SFML/Graphics.hpp>

class TitleScreen
{
private:
	sf::Texture TitleTexture;

public:
	sf::Sprite Sprite;

public:
	TitleScreen();
	~TitleScreen();

	void Load(std::string Dir);						// Load the texture and set the sprite
	void setPosition(const sf::Vector2f Position);  // Set the position of the sprite
};


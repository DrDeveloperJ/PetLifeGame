#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Texture playerTexture;

public:
	sf::Sprite Sprite;
	bool movementAllow;

public:
	void Initialize();
	void Load(int xindex, int yindex);
	void Update();
};


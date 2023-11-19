#pragma once
#include <SFML/Graphics.hpp>

class Player
{

public:
	sf::Texture playerTexture;
	sf::Sprite Sprite;
	bool movementAllow;

public:
	void Initialize();
	void setTexture(int xindex, int yindex);
	void Load(std::string dir);
	void Update();
};


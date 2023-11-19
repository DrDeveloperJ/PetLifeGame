#pragma once
#include <SFML/Graphics.hpp>

class Map
{
private:
	sf::Texture MapTexture;

public:
	sf::Sprite Sprite;

public:
	Map();
	~Map();

	void Load(std::string Dir);
	void Update();
	void setPosition(const sf::Vector2f Position);
};


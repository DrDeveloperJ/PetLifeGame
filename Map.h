#pragma once
#include <SFML/Graphics.hpp>

class Map
{
private:
	sf::Texture MapTexture;
	sf::Texture MapTexture2;
	sf::Texture MapTexture3;
	sf::Texture MapTexture4;

public:
	sf::Sprite Sprite;

public:
	Map();
	~Map();

	void LoadMap1(std::string map1Dir);	// Loads the texture from the directory for map 1
	void LoadMap2(std::string map2Dir);	// Loads the texture from the directory for map 2
	void LoadMap3(std::string map3Dir);	// Loads the texture from the directory for map 3
	void LoadMap4(std::string map4Dir);	// Loads the texture from the directory for map 4
	void switchMap(int map);																		// Switches the map
	void setPosition(const sf::Vector2f Position);													// Sets the position of the map
};


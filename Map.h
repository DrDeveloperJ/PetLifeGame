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

	void Load(std::string map1Dir, std::string map2Dir, std::string map3Dir, std::string map4Dir);	// Loads the textures from the directories
	void switchMap(int map);																		// Switches the map
	void setPosition(const sf::Vector2f Position);													// Sets the position of the map
};


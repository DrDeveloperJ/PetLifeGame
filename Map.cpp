#include "Map.h"
#include <iostream>

Map::Map()
{
}

Map::~Map()
{
}

void Map::LoadMap2(std::string map2Dir)
{
	// Load Map 2 Texture
	if (MapTexture2.loadFromFile(map2Dir))
	{
		std::cout << "Loaded Map 2 Texture" << std::endl;
	}
	else
	{
		std::cout << "Failed to load Map Texture" << std::endl;
	}
}

void Map::LoadMap3(std::string map3Dir)
{
	// Load Map 3 Texture
	if (MapTexture3.loadFromFile(map3Dir))
	{
		std::cout << "Loaded Map 3 Texture" << std::endl;
	}
	else
	{
		std::cout << "Failed to load Map Texture" << std::endl;
	}
}

void Map::LoadMap4(std::string map4Dir)
{
	// Load Map 4 Texture
	if (MapTexture4.loadFromFile(map4Dir))
	{
		std::cout << "Loaded Map 4 Texture" << std::endl;
	}
	else
	{
		std::cout << "Failed to load Map Texture" << std::endl;
	}
}

void Map::LoadMap1(std::string map1Dir)
{
    // Load Map Texture and set Sprite to 1st Map
    if (MapTexture.loadFromFile(map1Dir))
    {
        std::cout << "Loaded Map Texture" << std::endl;
        Sprite.setTexture(MapTexture);
    }
    else
    {
        std::cout << "Failed to load Map Texture" << std::endl;
    }
}

void Map::switchMap(int map)
{
	// Switch Map
    switch (map)
    {
	case 1:
		Sprite.setTexture(MapTexture);
		break;
	case 2:
		Sprite.setTexture(MapTexture2);
		break;
	case 3:
		Sprite.setTexture(MapTexture3);
		break;
	case 4:
		Sprite.setTexture(MapTexture4);
		break;
	default:
		break;
	}
}

void Map::setPosition(const sf::Vector2f Position)
{
    // Set Map Position
    Sprite.setPosition(Position);
}


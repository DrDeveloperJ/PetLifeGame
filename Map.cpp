#include "Map.h"
#include <iostream>

Map::Map()
{
}

Map::~Map()
{
}

void Map::Load(std::string map1Dir, std::string map2Dir, std::string map3Dir, std::string map4Dir)
{
    // Load Map Textures and set Sprite to 1st Map
    if ((MapTexture.loadFromFile(map1Dir)) && (MapTexture2.loadFromFile(map2Dir)) && (MapTexture3.loadFromFile(map3Dir)) && (MapTexture4.loadFromFile(map4Dir)))
    {
        std::cout << "Loaded Map Textures" << std::endl;
        Sprite.setTexture(MapTexture);
    }
    else
    {
        std::cout << "Failed to load Map Textures" << std::endl;
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


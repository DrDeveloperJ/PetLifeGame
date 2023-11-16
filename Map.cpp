#include "Map.h"
#include <iostream>

Map::Map()
{
}

Map::~Map()
{
}

void Map::Load(std::string Dir)
{
    if (MapTexture.loadFromFile(Dir))
    {
        std::cout << "Loaded Map Texture" << std::endl;
        Sprite.setTexture(MapTexture);
        Sprite.setTextureRect(sf::IntRect(0, 0, 2700, 680));
    }
    else
    {
        std::cout << "Failed to load Map Texture" << std::endl;
    }
}

void Map::Update()
{
}

void Map::setPosition(const sf::Vector2f Position)
{
    Sprite.setPosition(Position);
}


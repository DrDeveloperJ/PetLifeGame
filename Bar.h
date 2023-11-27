#pragma once
#include <SFML/Graphics.hpp>

class Bar
{
private:
	int value;
	sf::Sprite Sprite;
	sf::Texture barTexture;
	sf::Text displayedValue;
	int currentX = 0;
	bool empty = false;

public:
	Bar();
	~Bar();

	void Load(std::string dir);
	void Load(std::string dir, int indexX, int indexY, int sizeX, int sizeY);
	void setTexture(int indexX, int indexY, int sizeX, int sizeY);
	void Initialize(int givenValue, const sf::Vector2f Scale, sf::Font& font);
	void Initialize(int givenValue, const sf::Vector2f Scale);
	void updateValue(int newvalue);
	int getValue();
	void setPosition(const sf::Vector2f Position, const sf::Vector2f PositionText);
	void setPosition(const sf::Vector2f Position);
	void DrawTo(sf::RenderWindow& window);
	void DrawSpriteOnlyTo(sf::RenderWindow& window);
	void DecrementValue(int amount, float &gameTime, float timeBetweenSwitch);
	void DecrementHealthValue(int amount, float& gameTime, float timeBetweenSwitch);
};
#pragma once
#include <SFML/Graphics.hpp>

class Bar
{
private:
	int value;
	sf::Sprite Sprite;
	sf::Texture barTexture;
	sf::Text displayedValue;
	int currentX;
	bool empty = false;
	bool full = false;

public:
	Bar();
	~Bar();

	void Load(std::string dir);
	void Load(std::string dir, int indexX, int indexY, int sizeX, int sizeY);
	void setTexture(int indexX, int indexY, int sizeX, int sizeY);
	void Initialize(int givenValue, const sf::Vector2f Scale, sf::Font& font);
	void Initialize(bool empty, bool full, int givenValue, const sf::Vector2f Scale);
	void updateValue(int newvalue);
	int getValue();
	void resetValue();
	void setCurrentX(int currentXNew);
	void setPosition(const sf::Vector2f Position, const sf::Vector2f PositionText);
	void setPosition(const sf::Vector2f Position);
	void DrawTo(sf::RenderWindow& window);
	void DrawSpriteOnlyTo(sf::RenderWindow& window);
	void DecrementValue(int amount, float& gameTime, float timeBetweenSwitch);
	void IncrementValue(int amount, float& gameTime, float timeBetweenSwitch);
	void IncrementValue(int amount);
	void DecrementHealthValue(int amount, float& gameTime, float timeBetweenSwitch);
};
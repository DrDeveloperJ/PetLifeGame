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

	void Load(std::string dir);															// Loads the bar texture for bars which will not change such as the currency bar
	void Load(std::string dir, int indexX, int indexY, int sizeX, int sizeY);			// Loads the bar texture for bars which will change such as the hunger bar, or boredom bar for example
	void setTexture(int indexX, int indexY, int sizeX, int sizeY);						// Sets the texture of the bar (Used for changing the bar texture state for example when the hunger bar goes down)
	void Initialize(int givenValue, const sf::Vector2f Scale, sf::Font& font);			// Initializes the bar (Currency Bar)
	void Initialize(bool empty, bool full, int givenValue, const sf::Vector2f Scale);	// Initializes the bar (Hunger Bar, Boredom Bar, etc)
	void updateValue(int newvalue);														// Updates the value of the bar
	int getValue();																		// Returns the value of the bar
	void resetValue();																	// Resets the value of the bar
	void setCurrentX(int currentXNew);													// Sets the currentX of the bar
	void setPosition(const sf::Vector2f Position, const sf::Vector2f PositionText);		// Sets the position of the bar
	void setPosition(const sf::Vector2f Position);										// Sets the position of the bar
	void DrawTo(sf::RenderWindow& window);												// Draws the bar to the window
	void DrawSpriteOnlyTo(sf::RenderWindow& window);									// Draws the bar sprite only to the window
	void DecrementValue(int amount, float& gameTime, float timeBetweenSwitch);			// Decrements the value of the bar based on a timer
	void IncrementValue(int amount, float& gameTime, float timeBetweenSwitch);			// Increments the value of the bar based on a timer
	void IncrementValue(int amount);													// Increments the value of the bar
	void DecrementHealthValue(int amount, float& gameTime, float timeBetweenSwitch);	// Decrements the value of the Health bar based on a timer
};
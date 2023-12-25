#pragma once
#include "SFML/Graphics.hpp"

class Currency
{
private:
	sf::Sprite currencySprite;
	sf::Texture currencyTexture;
	int currentAnimationStage;
	float interval;
	bool active;

public :
	void Load(std::string dir);											// Loads the texture and sets the sprite
	void AnimationUpdate(float deltaTime, float timeBetweenSwitch);		// Updates the animation of the currency to show the next frame
	void initialize(sf::Vector2f position);								// Initializes the currency
	void draw(sf::RenderWindow& window);								// Draws the currency
	void setActive(bool newactive);										// Sets the currency to active or inactive
	bool getActive();													// Returns if the currency is active or not
};


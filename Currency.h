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
	void Load(std::string dir);
	void AnimationUpdate(float deltaTime, float timeBetweenSwitch);
	void initialize(sf::Vector2f position);
	void draw(sf::RenderWindow& window);
	void setActive(bool newactive);
	bool getActive();
};


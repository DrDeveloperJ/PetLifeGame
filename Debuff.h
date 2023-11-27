#pragma once
#include <SFML/Graphics.hpp>

class Debuff
{
private:
	bool active;
	sf::Sprite Sprite;
	sf::Texture DebuffTexture;

public:
	float change;

public:
	Debuff();
	~Debuff();

	void Load(std::string dir, sf::Vector2f Size);
	void Initialize(float newchange);
	void setPosition(sf::Vector2f position);
	void setActive(bool active);
	bool getActive();
	void DrawTo(sf::RenderWindow& window);
};


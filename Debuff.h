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

	Debuff();
	~Debuff();

	void Load(std::string dir);
	void Initialize(float newchange, sf::Vector2f Scale);
	void setPosition(sf::Vector2f position);
	void setActive(bool active);
	bool getActive();
	void DrawTo(sf::RenderWindow& window);
};


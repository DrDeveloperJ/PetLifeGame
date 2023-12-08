#pragma once
#include <SFML/Graphics.hpp>

class SleepingFunctionality
{
private:
	sf::Sprite darknessOverlay;
	sf::Texture darknessTexture;
	sf::Sprite sleepingZ;
	sf::Texture sleepingZTexture;
	bool active;
	bool rewardAllowed = false;

public:
	int currentZ = 0;

public:
	void Load(std::string dir, std::string zDir, sf::Vector2f position);
	void Draw(sf::RenderWindow& window);
	void setZ(sf::Vector2f position, sf::Vector2f scale, int rotateDegree);
	void setActive(bool newactive);
	bool getActive();
	void setRewardAllowed(bool newRewardAllowed);
	bool getRewardAllowed();
};


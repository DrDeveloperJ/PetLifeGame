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
	void Load(std::string dir, std::string zDir, sf::Vector2f position);	// Load the textures
	void Draw(sf::RenderWindow& window);									// Draw the textures
	void setZ(sf::Vector2f position, sf::Vector2f scale, int rotateDegree); // Set the position, scale, and rotation of the sleeping Z
	void setActive(bool newactive); 										// Set the active state of the sleeping functionality
	bool getActive();														// Return the active state of the sleeping functionality
	void setRewardAllowed(bool newRewardAllowed);							// Set the weither the player can get a reward or not
	bool getRewardAllowed();												// Return the weither the player can get a reward or not
};


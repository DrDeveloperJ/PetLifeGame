#include "SleepingFunctionality.h"

void SleepingFunctionality::Load(std::string dir, std::string zDir, sf::Vector2f position)
{
	// Load the darkness overlay texture and set the position
	darknessTexture.loadFromFile(dir);
	darknessOverlay.setTexture(darknessTexture);
	darknessOverlay.setPosition(position);

	// Load the sleeping Z texture
	sleepingZTexture.loadFromFile(zDir);
	sleepingZ.setTexture(sleepingZTexture);
}

void SleepingFunctionality::Draw(sf::RenderWindow& window)
{
	// Draw the darkness overlay and the sleeping Z
	window.draw(sleepingZ);
	window.draw(darknessOverlay);
}

void SleepingFunctionality::setZ(sf::Vector2f position, sf::Vector2f scale, int rotateDegree)
{
	// Set the position, scale, and rotation of the sleeping Z
	sleepingZ.setPosition(position);
	sleepingZ.setScale(scale);
	sleepingZ.setRotation(rotateDegree);
}

void SleepingFunctionality::setActive(bool newactive)
{
	// Set the active state of the sleeping functionality
	active = newactive;
}

bool SleepingFunctionality::getActive()
{
	// Return the active state of the sleeping functionality
	return active;
}

void SleepingFunctionality::setRewardAllowed(bool newRewardAllowed)
{
	// Set the weither the player can get a reward or not
	rewardAllowed = newRewardAllowed;
}

bool SleepingFunctionality::getRewardAllowed()
{
	// Return the weither the player can get a reward or not
	return rewardAllowed;
}

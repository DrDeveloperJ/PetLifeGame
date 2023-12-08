#include "SleepingFunctionality.h"

void SleepingFunctionality::Load(std::string dir, std::string zDir, sf::Vector2f position)
{
	darknessTexture.loadFromFile(dir);
	darknessOverlay.setTexture(darknessTexture);
	darknessOverlay.setPosition(position);

	sleepingZTexture.loadFromFile(zDir);
	sleepingZ.setTexture(sleepingZTexture);
}

void SleepingFunctionality::Draw(sf::RenderWindow& window)
{
	window.draw(sleepingZ);
	window.draw(darknessOverlay);
}

void SleepingFunctionality::setZ(sf::Vector2f position, sf::Vector2f scale, int rotateDegree)
{
	sleepingZ.setPosition(position);
	sleepingZ.setScale(scale);
	sleepingZ.setRotation(rotateDegree);
}

void SleepingFunctionality::setActive(bool newactive)
{
	active = newactive;
}

bool SleepingFunctionality::getActive()
{
	return active;
}

void SleepingFunctionality::setRewardAllowed(bool newRewardAllowed)
{
	rewardAllowed = newRewardAllowed;
}

bool SleepingFunctionality::getRewardAllowed()
{
	return rewardAllowed;
}

#include "BathMinigame.h"
#include <cstdlib>

BathMinigame::BathMinigame()
{
}

BathMinigame::~BathMinigame()
{
}

void BathMinigame::Load(std::string backgrounddir, std::string spongedir, std::string SpongeOnDir, std::string bathBardir)
{
	backgroundTexture.loadFromFile(backgrounddir);
	background.setTexture(backgroundTexture);

	spongeOnTexture.loadFromFile(SpongeOnDir);

	spongeTexture.loadFromFile(spongedir);
	sponge.setTexture(spongeTexture);

	bathBar.Load(bathBardir, 1200, 0, 200, 100);
}

void BathMinigame::SpongeMouseOver(sf::RenderWindow& window) // run the clock and bar updating just like for the other bars in 
//the same section, but only if the mouse is over the sponge (so add an if statement)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float bgX = sponge.getPosition().x;
	float bgY = sponge.getPosition().y;

	float bgXPosWidth = sponge.getPosition().x + sponge.getLocalBounds().width;
	float bgXPosHeight = sponge.getPosition().y + sponge.getLocalBounds().height;

	if (mouseX < bgXPosWidth && mouseX > bgX && mouseY < bgXPosHeight && mouseY > bgY)
	{
		overSponge = true;
	}
	else
	{
		overSponge = false;
	}
}

bool BathMinigame::isActive()
{
	return active;
}

void BathMinigame::Initialize(sf::Vector2f BackgroundPosition, sf::Vector2f SpongePosition, sf::Vector2f barPosition)
{
	background.setPosition(BackgroundPosition);

	sponge.setPosition(SpongePosition);

	bathBar.Initialize(true, false, 0, { 1.5, 1.5 });
	bathBar.setPosition(barPosition);
}

void BathMinigame::SpongeSetPosition(sf::Vector2f position)
{
	sponge.setPosition(position);
}

void BathMinigame::SpongeSwitchState(bool overSponge)
{
	if (overSponge)
	{
		sponge.setTexture(spongeOnTexture);
	}
	else
	{
		sponge.setTexture(spongeTexture);
	}
}

void BathMinigame::SpongeMoveAround(sf::Clock& spongeBathClock, float& spongeMoveAroundTime, float spongeBathTimeBetweenSwitch)
{
	if (spongeMoveAroundTime >= spongeBathTimeBetweenSwitch)
	{
		spongeMoveAroundTime = spongeBathClock.restart().asSeconds();

		std::srand(time(0));
		direction = rand() % 10;

		if (direction > 7)
		{
			direction -= 2;
		}
	}

	switch (direction)
	{
	case 0: // North
		sponge.setPosition(sponge.getPosition() + sf::Vector2f(0, -1.2));
		break;
	case 1: // North-East
		sponge.setPosition(sponge.getPosition() + sf::Vector2f(1.2, -1.2));
		break;
	case 2: // East
		sponge.setPosition(sponge.getPosition() + sf::Vector2f(1.2, 0));
		break;
	case 3: // South-East
		sponge.setPosition(sponge.getPosition() + sf::Vector2f(1.2, 1.2));
		break;
	case 4: // South
		sponge.setPosition(sponge.getPosition() + sf::Vector2f(0, 1.2));
		break;
	case 5: // South-West
		sponge.setPosition(sponge.getPosition() + sf::Vector2f(-1.2, 1.2));
		break;
	case 6: // West
		sponge.setPosition(sponge.getPosition() + sf::Vector2f(-1.2, 0));
		break;
	case 7: // North-West
		sponge.setPosition(sponge.getPosition() + sf::Vector2f(-1.2, -1.2));
		break;
	}

	if (sponge.getPosition().y <= background.getPosition().y)
	{
		sponge.setPosition(sf::Vector2f(650, 350));
	}
	else if (sponge.getPosition().y >= (background.getPosition().y + background.getLocalBounds().height))
	{
		sponge.setPosition(sf::Vector2f(650, 350));
	}

	if (sponge.getPosition().x <= background.getPosition().x)
	{
		sponge.setPosition(sf::Vector2f(700, 300));
	}
	else if (sponge.getPosition().x >= (background.getPosition().x + background.getLocalBounds().width))
	{
		sponge.setPosition(sf::Vector2f(700, 300));
	}
}

void BathMinigame::DrawTo(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(sponge);
	bathBar.DrawSpriteOnlyTo(window);
}

void BathMinigame::setActive(bool newactive)
{
	active = newactive;
}

bool BathMinigame::isOverSponge()
{
	return overSponge;
}

void BathMinigame::miniGameFinishedCheck(Debuff& Unclean, sf::Clock& uncleanGameClock, float& hungerTimeBetweenSwitch, float& energyTimeBetweenSwitch, float& boredomTimeBetweenSwitch)
{
	if (bathBar.getValue() == 6)
	{
		active = false;
		Unclean.setActive(false);
		uncleanGameClock.restart();
		hungerTimeBetweenSwitch += 10.0f;
		energyTimeBetweenSwitch += 10.0f;
		boredomTimeBetweenSwitch += 10.0f;
		overSponge = false;
	}
}

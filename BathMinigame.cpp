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
	// Load textures for the minigame
	backgroundTexture.loadFromFile(backgrounddir);
	background.setTexture(backgroundTexture);

	spongeOnTexture.loadFromFile(SpongeOnDir);

	spongeTexture.loadFromFile(spongedir);
	sponge.setTexture(spongeTexture);

	bathBar.Load(bathBardir, 1200, 0, 200, 100);
}

void BathMinigame::SpongeMouseOver(sf::RenderWindow& window)
{
	// Sets overSponge based on if the mouse is over the sponge or not
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
	// Returns if the minigame is active or not
	return active;
}

void BathMinigame::Initialize(sf::Vector2f BackgroundPosition, sf::Vector2f SpongePosition, sf::Vector2f barPosition)
{
	// Initializes the minigame
	background.setPosition(BackgroundPosition);

	sponge.setPosition(SpongePosition);

	bathBar.Initialize(true, false, 0, { 1.5, 1.5 });
	bathBar.setPosition(barPosition);
}

void BathMinigame::SpongeSetPosition(sf::Vector2f position)
{
	// Sets the position of the sponge
	sponge.setPosition(position);
}

void BathMinigame::SpongeSwitchState(bool overSponge)
{
	// Switches the state of the sponge (Scrubbing or not scrubbing)
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
	// Moves the sponge around the bath in random directions
	if (spongeMoveAroundTime >= spongeBathTimeBetweenSwitch)
	{
		spongeMoveAroundTime = spongeBathClock.restart().asSeconds();

		std::srand(time(0));
		direction = rand() % 10;

		// Ensures the sponge doesnt go in a non existant direction
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

	// Ensures the sponge doesnt go off the screen
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
	// Draws the minigame to the window
	window.draw(background);
	window.draw(sponge);
	bathBar.DrawSpriteOnlyTo(window);
}

void BathMinigame::setActive(bool newactive)
{
	// Sets the minigame to active or inactive
	active = newactive;
}

bool BathMinigame::isOverSponge()
{
	// Returns if the mouse is over the sponge or not
	return overSponge;
}

void BathMinigame::miniGameFinishedCheck(Debuff& Unclean, sf::Clock& uncleanGameClock, float& hungerTimeBetweenSwitch, float& energyTimeBetweenSwitch, float& boredomTimeBetweenSwitch, Currency &currency, Bar &currencyBar)
{
	// Checks if the minigame is finished
	if (bathBar.getValue() == 6)
	{
		// If the minigame is finished, set the minigame to inactive
		active = false;

		// Set the unclean debuff to inactive
		Unclean.setActive(false);

		// Reset the unclean debuff clock
		uncleanGameClock.restart();
		hungerTimeBetweenSwitch += 10.0f;
		energyTimeBetweenSwitch += 10.0f;
		boredomTimeBetweenSwitch += 10.0f;

		// Award currency
		overSponge = false;
		currency.setActive(true);
		int newCurrencyValue = currencyBar.getValue() + 1;
		currencyBar.updateValue(newCurrencyValue);
	}
}

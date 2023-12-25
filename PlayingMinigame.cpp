#include "PlayingMinigame.h"
#include <iostream>

PlayingMinigame::PlayingMinigame()
{
}

PlayingMinigame::~PlayingMinigame()
{
}

void PlayingMinigame::Load(std::string backgroundDir, std::string explosionDir, std::string mouseDir)
{
	// Loads the textures and sets the sprites
	backgroundTexture.loadFromFile(backgroundDir);
	mouseTexture.loadFromFile(mouseDir);
	explosionTexture.loadFromFile(explosionDir);
	
	// Sets the sprites to the textures
	background.setTexture(backgroundTexture);
	mouse.setTexture(mouseTexture);
	explosion.setTexture(explosionTexture);
}

void PlayingMinigame::MouseBlast(Bar& boredomBar)
{
	std::cout << "MouseBlast" << std::endl;

	// Show the explosion
	explosion.setPosition(mouse.getPosition().x, mouse.getPosition().y);
	explosionTimer.restart().asSeconds();
	
	// Increment the boredom bar
	boredomBar.IncrementValue(1);

	// Pick a random position for the mouse to move to
	srand(time(0));
	positionx = rand() % 1000;
	positiony = rand() % 600;

	// Check if the mouse is going to move off the minigame background screen and if so, move it back
	if (positionx + 102 > (background.getPosition().x + background.getLocalBounds().width))
	{
		std::cout << "left 100";
		positionx -= 100;
	}
	if (positionx < background.getPosition().x)
	{
		std::cout << "right 100";
		positionx += 100;
	}
	if (positiony + 102 > (background.getPosition().y + background.getLocalBounds().height))
	{
		std::cout << "up 90";
		positiony -= 90;
	}
	if (positiony < background.getPosition().y)
	{
		std::cout << "down 90";
		positiony += 90;
	}

	// Move the mouse to the new position
	mouse.setPosition(positionx, positiony);
}

void PlayingMinigame::Initialize(sf::Vector2f backgroundPosition)
{
	// Initializes the minigame
	background.setPosition(backgroundPosition);
	mouse.setPosition({ 600, 200 });
}

bool PlayingMinigame::IsOverMouse(sf::RenderWindow& window)
{
	//returns weither mouse (cursor) is over the mouse (animal) or not
    if (active)
    {
        float cursorX = sf::Mouse::getPosition(window).x;
        float cursorY = sf::Mouse::getPosition(window).y;

        float spriteX = mouse.getPosition().x;
        float spriteY = mouse.getPosition().y;

        float spriteXPosWidth = mouse.getPosition().x + (mouse.getLocalBounds().width);
        float spriteYPosHeight = mouse.getPosition().y + (mouse.getLocalBounds().height);

        if (cursorX < spriteXPosWidth && cursorX > spriteX && cursorY < spriteYPosHeight && cursorY > spriteY)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false; //return false in case not active (to avoid errors)
}

void PlayingMinigame::SetActive(bool newActive, Bar& boredomBar)
{
	// Sets the minigame to active or inactive
	active = newActive;

	// Checks if the boredom bar is low enough to allow a reward to be given (currency)
	if (boredomBar.getValue() < 3)
	{
		allowedReward = true;
	}
	else
	{
		allowedReward = false;
	}
}

bool PlayingMinigame::isActive()
{
	// Returns if the minigame is active or not
	return active;
}

void PlayingMinigame::MiniGameFinishedCheck(Bar& boredomBar, Currency& currency, Bar& currencyBar)
{
	// Checks if the minigame is finished
	if (boredomBar.getValue() == 6)
	{
		// Sets the minigame to inactive
		active = false;

		// Gives the player a reward if they are allowed to
		if (allowedReward)
		{
			currency.setActive(true);
			int newCurrencyValue = currencyBar.getValue() + 1;
			currencyBar.updateValue(newCurrencyValue);
			allowedReward = false;
		}
	}
}

void PlayingMinigame::Draw(sf::RenderWindow& window)
{
	// Renders the minigame
	window.draw(background);
	window.draw(mouse);

	// Ensures the eplosion is only shown for 0.5 seconds, when shown
	if (explosionTimer.getElapsedTime().asSeconds() < 0.5f)
	{
		window.draw(explosion);
	}
}

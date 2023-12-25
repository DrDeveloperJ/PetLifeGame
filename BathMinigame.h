#pragma once
#include <SFML/Graphics.hpp>
#include "Bar.h"
#include "Debuff.h"
#include "Currency.h"

class BathMinigame
{
private:
	sf::Texture spongeTexture;
	sf::Texture spongeOnTexture;
	sf::Texture backgroundTexture;

	sf::Sprite sponge;
	sf::Sprite background;
	bool overSponge;
	bool active;
	int direction = 1;

public:
	Bar bathBar;

public:
	BathMinigame();
	~BathMinigame();

	void Load(std::string backgrounddir, std::string spongedir, std::string SpongeOnDir, std::string bathBardir);		// Loads the textures and sets the sprites
	void Initialize(sf::Vector2f BackgroundPosition, sf::Vector2f SpongePosition, sf::Vector2f barPosition);			// Initializes the minigame
	void SpongeMouseOver(sf::RenderWindow& window);																		// Checks if the mouse is over the sponge
	void SpongeSetPosition(sf::Vector2f position);																		// Sets the position of the sponge
	void SpongeSwitchState(bool overSponge);																			// Switches the state of the sponge
	void SpongeMoveAround(sf::Clock& spongeBathClock, float& spongeMoveAroundTime, float spongeBathTimeBetweenSwitch);	// Moves the sponge around randomly
	bool isActive();																									// Returns if the minigame is active or not
	void setActive(bool newactive);																						// Sets the minigame to active or inactive
	bool isOverSponge();																								// Returns if the mouse is over the sponge or not
	void miniGameFinishedCheck(Debuff& Unclean, sf::Clock& uncleanGameClock, float& hungerTimeBetweenSwitch, float& energyTimeBetweenSwitch, float& boredomTimeBetweenSwitch, Currency& currency, Bar &currencyBar);
	void DrawTo(sf::RenderWindow& window);																				// Draws the sponge and the background
};


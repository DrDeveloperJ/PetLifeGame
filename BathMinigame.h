#pragma once
#include <SFML/Graphics.hpp>
#include "Bar.h"
#include "Debuff.h"

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

	void Load(std::string backgrounddir, std::string spongedir, std::string SpongeOnDir, std::string bathBardir);
	void Initialize(sf::Vector2f BackgroundPosition, sf::Vector2f SpongePosition, sf::Vector2f barPosition);
	void SpongeMouseOver(sf::RenderWindow& window);
	void SpongeSetPosition(sf::Vector2f position);
	void SpongeSwitchState(bool overSponge);
	void SpongeMoveAround(sf::Clock& spongeBathClock, float& spongeMoveAroundTime, float spongeBathTimeBetweenSwitch);
	bool isActive();
	void setActive(bool newactive);
	bool isOverSponge();
	void miniGameFinishedCheck(Debuff& Unclean, sf::Clock& uncleanGameClock, float& hungerTimeBetweenSwitch, float& energyTimeBetweenSwitch, float& boredomTimeBetweenSwitch);
	void DrawTo(sf::RenderWindow& window);
};


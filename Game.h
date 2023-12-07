#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Button.h"
#include "TitleScreen.h"
#include "Bar.h"
#include "Debuff.h"
#include "BathMinigame.h"

class Game
{

private:
	Player player;
	Map map;
	Button welcome;
	TitleScreen title;
	bool welcomeEnabled = true;

	sf::Font arial;
	sf::RenderWindow* window;
	sf::Event sfEvent;
	std::string currentArea;

	sf::Clock clock;
	sf::Clock hungerGameClock;
	sf::Clock energyGameClock;
	sf::Clock boredomGameClock;
	sf::Clock healthGameClock;
	sf::Clock spongeBathClock;
	sf::Clock bathClock;

	float hungerTimeBetweenSwitch = 15.0f;
	float energyTimeBetweenSwitch = 15.0f;
	float boredomTimeBetweenSwitch = 15.0f;
	float uncleanTimeBetweenSwitch = 5.0f;
	float healthTimeBetweenSwitch = 2.0f;
	float spongeBathTimeBetweenSwitch = 4.0f;
	float bathTimeBetweenSwitch = 0.5f;


	float deltatime = 0.0f;
	float hungerGameTime = 0.0f;
	float energyGameTime = 0.0f;
	float boredomGameTime = 0.0f;
	float uncleanGameTime = 0.0f;
	float healthGameTime = 0.0f;
	float spongeMoveAroundTime = 0.0f;
	float bathTime = 0.0f;

	Bar currencyBar;
	Bar healthBar;
	Bar hungerBar;
	Bar energyBar;
	Bar boredomBar;

	Button goInside;
	Button playAround;

	Button EntryWay;
	Button Kitchen;
	Button Bedroom;
	Button Bathroom;
	Button GoOutside;

	Button bathButton;

	sf::Clock uncleanGameClock;
	Debuff Unclean;
	BathMinigame bathMinigame;

	void initWindow();

public:
	Game();
	virtual ~Game();
	void updateSFMLEvents();
	void update();
	void render();
	void run();

};


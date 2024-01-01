#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <array>
#include <functional>
#include <future>
#include <vector>
#include <thread>

#include "Player.h"
#include "Map.h"
#include "Button.h"
#include "TitleScreen.h"
#include "Bar.h"
#include "Debuff.h"
#include "BathMinigame.h"
#include "Currency.h"
#include "SleepingFunctionality.h"
#include "EatingMinigame.h"
#include "PlayingMinigame.h"
#include "DifficultyUI.h"
#include "Shop.h"
#include "GameOver.h"

class Game
{

private:
	int difficulty = 1; // 1 = easy, 2 = hard
	Button difficultyButton;
	DifficultyUI difficultyUI;

	// Create a vector to store the futures
	std::vector<std::future<void>> futures;

	Player player;
	Map map;
	Button welcome;
	TitleScreen title;
	bool welcomeEnabled = true;
	GameOver gameOver;

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
	sf::Clock energyIncrementClock;
	sf::Clock foodGameClock;

	float hungerTimeBetweenSwitch = 12.0f;
	float energyTimeBetweenSwitch = 12.0f;
	float boredomTimeBetweenSwitch = 12.0f;
	float uncleanTimeBetweenSwitch = 19.0f;
	float healthTimeBetweenSwitch = 2.5f;
	float spongeBathTimeBetweenSwitch = 4.0f;
	float bathTimeBetweenSwitch = 0.5f;
	float energyTimeBetweenIncrement = 1.0f;
	float foodTimeBetweenSwitch = 4.0f;
	float uncleanDebuffTime = 5.0f;

	float deltatime = 0.0f;
	float hungerGameTime = 0.0f;
	float energyGameTime = 0.0f;
	float boredomGameTime = 0.0f;
	float uncleanGameTime = 0.0f;
	float healthGameTime = 0.0f;
	float spongeMoveAroundTime = 0.0f;
	float bathTime = 0.0f;
	float energyIncrementTime = 0.0f;
	float foodMoveAroundTime = 0.0f;

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

	Currency currency;

	Button bathButton;
	sf::Clock uncleanGameClock;
	Debuff Unclean;
	BathMinigame bathMinigame;

	Button sleepButton;
	Button wakeButton;
	SleepingFunctionality sleepFunctionality;
	float sleepingZIncrement = 0.0f;

	Button eatButton;
	EatingMinigame eatingMinigame;
	sf::Texture kitchenTableOverlayTexture;
	sf::Sprite kitchenTableOverlay;

	PlayingMinigame playingMinigame;

	Button shopButton;
	Shop mapShop;

	void initWindow();

public:
	Game();
	~Game();
	void updateSFMLEvents();	// Update based on SFML events (Inputs)
	void update();				// Update the game
	void render();				// Render the game
	void run();					// Run the game

};


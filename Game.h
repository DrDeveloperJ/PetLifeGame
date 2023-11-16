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

class Game
{

private:
	Player player;
	Map map;
	Button welcome;
	bool welcomeEnabled = true;
	sf::Font arial;
	sf::RenderWindow *window;
	sf::Event sfEvent;
	std::string currentArea;

	void initWindow();

public:
	Game();
	virtual ~Game();
	void updateSFMLEvents();
	void update();
	void render();
	void run();

};


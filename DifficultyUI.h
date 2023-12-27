#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class DifficultyUI
{
private:
	//HARD TO EASY = +4.0f
	//EASY TO HARD = -4.0f

	//Health HARD TO EASY = +1.5f
	//Health EASY TO HARD = -1.5f

	//Default = Easy

	sf::Texture BackgroundTexture;
	sf::Sprite BackgroundSprite;

	Button easyButton;
	Button hardButton;

	bool active;

public:
	DifficultyUI();
	~DifficultyUI();

	void Load(std::string Background, std::string easyDir, std::string onEasyDir, std::string hardDir, std::string onHardDir);
	void Initialize(sf::Vector2f backgroundPos, sf::Vector2f easyPos, sf::Vector2f hardPos);	// Set the initial position of the background and buttons
	void ButtonsMouseOver(sf::RenderWindow& window);											// Check if the mouse is over the buttons
	int getEasyButtonState();																	// Get the state of the easy button
	int getHardButtonState();																	// Get the state of the hard button
	void setEasyButtonState(int newstate);														// Set the state of the easy button
	void setHardButtonState(int newstate);														// Set the state of the hard button
	void setActive(bool newactive);																// Set the active state of the UI
	bool getActive();																			// Get the active state of the UI
	void drawTo(sf::RenderWindow& window);														// Draw the UI to the window
};


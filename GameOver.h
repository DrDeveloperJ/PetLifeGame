#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class GameOver
{
private:
	Button restartButton;
	sf::Texture gameOverTexture;
	sf::Sprite gameOverScreen;

	bool gameOverEnabled = false;

public:
	GameOver();
	~GameOver();

	void Load(std::string gameOverDir, std::string restartDir, std::string onRestartDir);	// Loads the game over screen and the restart button
	void restartButtonMouseOver(sf::RenderWindow& window);									// Checks if the mouse is over the restart button and changes the state accordingly
	int getRestartButtonState();															// Returns the state of the restart button
	void setRestartButtonState(int newState);												// Sets the state of the restart button
	bool getGameOverEnabled();																// Returns if the game over screen is enabled
	void setGameOverEnabled(bool newenabled);												// Sets if the game over screen is enabled
	void Draw(sf::RenderWindow& window);													// Draws the game over screen to the window
};


#include "GameOver.h"

GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

void GameOver::Load(std::string gameOverDir, std::string restartDir, std::string onRestartDir)
{
	// Loads the game over screen
	if (gameOverTexture.loadFromFile(gameOverDir))
	{
		std::cout << "Loaded Game Over Screen" << std::endl;
		gameOverScreen.setTexture(gameOverTexture);
	}
	else
	{
		std::cout << "Failed to load Game Over Screen" << std::endl;
	}

	// Loads the restart button and sets its position
	restartButton.Load(restartDir, onRestartDir, sf::Vector2f(200, 50), 0, 0, 200, 50);
	restartButton.setPosition(sf::Vector2f(600, 300));
}

void GameOver::restartButtonMouseOver(sf::RenderWindow& window)
{
	// Checks if the mouse is over the restart button and changes the state accordingly
	restartButton.MouseOver(window);
}

int GameOver::getRestartButtonState()
{
	// Returns the state of the restart button
	return restartButton.ButtonState;
}

void GameOver::setRestartButtonState(int newState)
{
	// Sets the state of the restart button
	restartButton.switchState(newState);
}

bool GameOver::getGameOverEnabled()
{
	// Returns if the game over screen is enabled
	return gameOverEnabled;
}

void GameOver::setGameOverEnabled(bool newenabled)
{
	// Sets if the game over screen is enabled
	gameOverEnabled = newenabled;
}

void GameOver::Draw(sf::RenderWindow& window)
{
	// Draws the game over screen and the restart button to the window
	window.draw(gameOverScreen);
	restartButton.DrawTo(window);
}

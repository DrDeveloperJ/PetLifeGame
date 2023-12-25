#pragma once
#include <SFML/Graphics.hpp>
#include "Bar.h"
#include "Currency.h"

class PlayingMinigame
{
private:
	bool active;

	sf::Texture backgroundTexture;
	sf::Sprite background;

	sf::Texture mouseTexture;
	sf::Sprite mouse;

	sf::Texture explosionTexture;
	sf::Sprite explosion;
	sf::Clock explosionTimer;

	int positionx;
	int positiony;
	bool allowedReward;

public:
	PlayingMinigame();
	~PlayingMinigame();

	void Load(std::string backgroundDir, std::string explosionDir, std::string mouseDir); // Loads the textures and sets the sprites
	void MouseBlast(Bar& boredomBar);													  // Blasts the mouse
	void Initialize(sf::Vector2f backgroundPosition);									  // Initializes the minigame
	bool IsOverMouse(sf::RenderWindow& window);											  // Returns weither mouse (cursor) is over the mouse (animal) or not
	void SetActive(bool newActive, Bar& boredomBar);									  // Sets the minigame to active or inactive
	bool isActive();																	  // Returns if the minigame is active or not
	void MiniGameFinishedCheck(Bar& boredomBar, Currency& currency, Bar& currencyBar);	  // Checks if the minigame is finished
	void Draw(sf::RenderWindow& window);												  // Draws all the food and the background
};


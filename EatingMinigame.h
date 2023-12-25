#pragma once
#include <SFML/Graphics.hpp>
#include "Bar.h"
#include "Debuff.h"
#include "Currency.h"

class EatingMinigame
{
private:
	bool active;

	sf::Sprite background;
	sf::Texture backgroundTexture;

	sf::Texture foodTexture;
	sf::Texture correctFoodTexture;
	sf::Texture incorrectFoodTexture;

	sf::Sprite currentLookedForFood;

	sf::Sprite food1;
	sf::Sprite food2;
	sf::Sprite food3;
	sf::Sprite food4;
	sf::Sprite food5;
	sf::Sprite food6;
	sf::Sprite food7;
	sf::Sprite food8;

	int direction;
	bool allowTimerReset;
	bool allowedReward;

public:
	EatingMinigame();
	~EatingMinigame();

	void Load(std::string backgroundDir, std::string foodDir, std::string correctFoodDir, std::string incorrectFoodDir); // Loads the textures and sets the sprites
	void FoodSwitchState(const int& foodNumber, bool& state, Bar& hungerBar);											 // Switches the food to the correct or incorrect state
	void Initialize(sf::Vector2f backgroundPosition);																	 // Initializes the minigame
	bool CheckCorrectFood(sf::Sprite* foodPick);
	void SetFoodType(int food, int randomFoodChoice);																	 // Sets the type of an individual food
	void resetFoodTextures();																							 // Resets all the food textures to the default
	void SetEachFoodType();																								 // Sets the type of each food
	bool IsOverFood(sf::RenderWindow& window, int food);																 // Returns weither mouse is over the food or not
	void SetActive(bool newActive, Bar& hungerBar);																		 // Sets the minigame to active or inactive
	bool isActive();																									 // Returns if the minigame is active or not
	void MiniGameFinishedCheck(Bar& hungerBar, Currency& currency, Bar& currencyBar);									 // Checks if the minigame is finished
	void Draw(sf::RenderWindow& window);																				 // Draws all the food and the background
};


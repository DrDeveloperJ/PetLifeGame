#pragma once
#include <SFML/Graphics.hpp>

class Player // Class for the player
{
private:
	int currentAnimationStage;
	int previousRow;
	float interval;

public:
	sf::Texture playerTexture; // Texture for the player
	sf::Sprite Sprite; // Sprite for the player
	bool movementAllow; // If the player can move or not
	bool visible; // If the player is visible or not

	void Initialize(); // Initialize the player
	void setTexture(int xindex, int yindex); // Set the texture for the player
	void setTexture(int xindex, int yindex, int width, int height); // Set the texture for the player
	void Load(std::string dir); // Load the texture for the player
	void Update(); // Update the player
	void AnimationUpdate(int row, float deltaTime, float timeBetweenSwitch); // Set the current animation for the player
};
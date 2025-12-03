#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class Shop
{
private:
	sf::Texture BackgroundTexture;
	sf::Sprite BackgroundSprite;

	sf::Texture purchasedTexture;
	sf::Texture onPurchasedTexture;

	Button Map1Button;
	Button Map2Button;
	Button Map3Button;
	Button Map4Button;

	bool Map1Purchased = false;
	bool Map2Purchased = false;
	bool Map3Purchased = false;
	bool Map4Purchased = false;

	bool active;

public:
	Shop();
	~Shop();

	void Load(std::string Background, std::string Map1Dir, std::string onMap1Dir, std::string Map2Dir, std::string onMap2Dir, std::string Map3Dir, std::string onMap3Dir, std::string Map4Dir, std::string onMap4Dir);
	void Initialize(sf::Vector2f backgroundPos, sf::Vector2f Map1Pos, sf::Vector2f Map2Pos, sf::Vector2f Map3Pos, sf::Vector2f Map4Pos);	// Set the initial position of the background and buttons
	void ButtonsMouseOver(sf::RenderWindow& window);											// Check if the mouse is over the buttons
	bool getPurchased(int button);																// Get the purchased state of the button
	void setCurrentButton(int button);															// Set the button to the current butto
	int getMap1ButtonState();																	// Get the state of the Map1 button
	int getMap2ButtonState();																	// Get the state of the Map2 button
	int getMap3ButtonState();																	// Get the state of the Map3 button
	int getMap4ButtonState();																	// Get the state of the Map4 button
	void setMap1ButtonState(int newstate);														// Set the state of the Map1 button
	void setMap2ButtonState(int newstate);														// Set the state of the Map2 button
	void setMap3ButtonState(int newstate);														// Set the state of the Map3 button
	void setMap4ButtonState(int newstate);														// Set the state of the Map4 button
	void setActive(bool newactive);																// Set the active state of the UI
	bool getActive();																			// Get the active state of the UI
	void resetOtherButtons(int button);															// Reset the other buttons
	void setPurchased(int button);																// Set the button to purchased
	void drawTo(sf::RenderWindow& window);														// Draw the UI to the window
};

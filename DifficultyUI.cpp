#include "DifficultyUI.h"

DifficultyUI::DifficultyUI()
{
}

DifficultyUI::~DifficultyUI()
{
}

void DifficultyUI::Load(std::string Background, std::string easyDir, std::string onEasyDir, std::string hardDir, std::string onHardDir)
{
	// load the background texture
	BackgroundTexture.loadFromFile(Background);
	BackgroundSprite.setTexture(BackgroundTexture);

	// load the easy button
	easyButton.Load(easyDir, onEasyDir, sf::Vector2f(200.0f, 50.0f), 0, 0, 200, 50);

	// load the hard button
	hardButton.Load(hardDir, onHardDir, sf::Vector2f(200.0f, 50.0f), 0, 0, 200, 50);
}

void DifficultyUI::Initialize(sf::Vector2f backgroundPos, sf::Vector2f easyPos, sf::Vector2f hardPos)
{
	// set the position of the background
	BackgroundSprite.setPosition(backgroundPos);

	// set the position of the easy button
	easyButton.setPosition(easyPos);

	// set the position of the hard button
	hardButton.setPosition(hardPos);
}

void DifficultyUI::ButtonsMouseOver(sf::RenderWindow& window)
{
	// check if the mouse is over the easy button
	easyButton.MouseOver(window);

	// check if the mouse is over the hard button
	hardButton.MouseOver(window);
}

int DifficultyUI::getEasyButtonState()
{
	// return the state of the easy button
	return easyButton.ButtonState;
}

int DifficultyUI::getHardButtonState()
{ 
	// return the state of the hard button
	return hardButton.ButtonState;
}

void DifficultyUI::setEasyButtonState(int newstate)
{
	// set the state of the easy button
	easyButton.ButtonState = newstate;
}

void DifficultyUI::setHardButtonState(int newstate)
{
	// set the state of the hard button
	hardButton.ButtonState = newstate;
}

void DifficultyUI::setActive(bool newactive)
{
	// set the active state of the difficulty UI
	active = newactive;
}

bool DifficultyUI::getActive()
{
	// return the active state of the difficulty UI
	return active;
}

void DifficultyUI::drawTo(sf::RenderWindow& window)
{
	//draw the background
	window.draw(BackgroundSprite);

	//draw the easy button
	easyButton.DrawTo(window);

	//draw the hard button
	hardButton.DrawTo(window);
}

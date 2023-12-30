#include "Shop.h"

Shop::Shop()
{
}

Shop::~Shop()
{
}

void Shop::Load(std::string Background, std::string Map1Dir, std::string onMap1Dir, std::string Map2Dir, std::string onMap2Dir, std::string Map3Dir, std::string onMap3Dir, std::string Map4Dir, std::string onMap4Dir)
{
	// load the background texture
	BackgroundTexture.loadFromFile(Background);
	BackgroundSprite.setTexture(BackgroundTexture);

	// load the purchased texture
	purchasedTexture.loadFromFile(Map1Dir);

	// load the on purchased texture
	onPurchasedTexture.loadFromFile(onMap1Dir);

	// load the map 1 button
	Map1Button.Load(Map1Dir, onMap1Dir, sf::Vector2f(200.0f, 50.0f), 0, 0, 200, 50);

	// load the map 2 button
	Map2Button.Load(Map2Dir, onMap2Dir, sf::Vector2f(200.0f, 50.0f), 0, 0, 200, 50);

	// load the map 3 button
	Map3Button.Load(Map3Dir, onMap3Dir, sf::Vector2f(200.0f, 50.0f), 0, 0, 200, 50);

	// load the map 4 button
	Map4Button.Load(Map4Dir, onMap4Dir, sf::Vector2f(200.0f, 50.0f), 0, 0, 200, 50);
}

void Shop::Initialize(sf::Vector2f backgroundPos, sf::Vector2f Map1Pos, sf::Vector2f Map2Pos, sf::Vector2f Map3Pos, sf::Vector2f Map4Pos)
{
	// set the position of the background
	BackgroundSprite.setPosition(backgroundPos);

	// set the position of the map 1 button
	Map1Button.setPosition(Map1Pos);

	// set the position of the map 2 button
	Map2Button.setPosition(Map2Pos);

	// set the position of the map 3 button
	Map3Button.setPosition(Map3Pos);

	// set the position of the map 4 button
	Map4Button.setPosition(Map4Pos);

	// set the map 1 purchased state to true
	Map1Purchased = true;
}

void Shop::ButtonsMouseOver(sf::RenderWindow& window)
{
	// check if the mouse is over the map 1 button
	Map1Button.MouseOver(window);

	// check if the mouse is over the map 2 button
	Map2Button.MouseOver(window);

	// check if the mouse is over the map 3 button
	Map3Button.MouseOver(window);

	// check if the mouse is over the map 4 button
	Map4Button.MouseOver(window);
}

int Shop::getMap1ButtonState()
{
	return Map1Button.ButtonState;
}

int Shop::getMap2ButtonState()
{
	return Map2Button.ButtonState;
}

int Shop::getMap3ButtonState()
{
	return Map3Button.ButtonState;
}

int Shop::getMap4ButtonState()
{
	return Map4Button.ButtonState;
}

bool Shop::getPurchased(int button)
{
	switch (button)
	{
		case 1:
			return Map1Purchased;
			break;
		case 2:
			return Map2Purchased;
			break;
		case 3:
			return Map3Purchased;
			break;
		case 4:
			return Map4Purchased;
			break;
	}
}

void Shop::setCurrentButton(int button)
{
	switch (button)
	{
		case 1:
			Map1Button.setTexture(200, 0, 200, 50);
			break;
		case 2:
			Map2Button.setTexture(200, 0, 200, 50);
			break;
		case 3:
			Map3Button.setTexture(200, 0, 200, 50);
			break;
		case 4:
			Map4Button.setTexture(200, 0, 200, 50);
			break;
	}
}

void Shop::setMap1ButtonState(int newstate)
{
	Map1Button.switchState(newstate);
}

void Shop::setMap2ButtonState(int newstate)
{
	Map2Button.switchState(newstate);
}

void Shop::setMap3ButtonState(int newstate)
{
	Map3Button.switchState(newstate);
}

void Shop::setMap4ButtonState(int newstate)
{
	Map4Button.switchState(newstate);
}

void Shop::setActive(bool newactive)
{
	active = newactive;
}

bool Shop::getActive()
{
	return active;
}

void Shop::resetOtherButtons(int button)
{
	// reset the other buttons
	switch (button)
	{
	case 1:
		Map1Button.active = true;
		Map2Button.setTexture(0, 0, 200, 50);
		Map2Button.active = true;
		Map3Button.setTexture(0, 0, 200, 50);
		Map3Button.active = true;
		Map4Button.setTexture(0, 0, 200, 50);
		Map4Button.active = true;
		break;
	case 2:
		Map1Button.setTexture(0, 0, 200, 50);
		Map1Button.active = true;
		Map2Button.active = true;
		Map3Button.setTexture(0, 0, 200, 50);
		Map3Button.active = true;
		Map4Button.setTexture(0, 0, 200, 50);
		Map4Button.active = true;
		break;
	case 3:
		Map1Button.setTexture(0, 0, 200, 50);
		Map1Button.active = true;
		Map2Button.setTexture(0, 0, 200, 50);
		Map2Button.active = true;
		Map3Button.active = true;
		Map4Button.setTexture(0, 0, 200, 50);
		Map4Button.active = true;
		break;
	case 4:
		Map1Button.setTexture(0, 0, 200, 50);
		Map1Button.active = true;
		Map2Button.setTexture(0, 0, 200, 50);
		Map2Button.active = true;
		Map3Button.setTexture(0, 0, 200, 50);
		Map3Button.active = true;
		Map4Button.active = true;
		break;
	}
}

void Shop::setPurchased(int button)
{
	// set the button to purchased
	switch (button)
	{
	case 1:
		Map1Button.updateButtonTexture(purchasedTexture, onPurchasedTexture);
		Map1Button.setTexture(200, 0, 200, 50);
		Map1Button.active = false;
		Map1Purchased = true;
		break;
	case 2:
		Map2Button.updateButtonTexture(purchasedTexture, onPurchasedTexture);
		Map2Button.setTexture(200, 0, 200, 50);
		Map2Button.active = false;
		Map2Purchased = true;
		break;
	case 3:
		Map3Button.updateButtonTexture(purchasedTexture, onPurchasedTexture);
		Map3Button.setTexture(200, 0, 200, 50);
		Map3Button.active = false;
		Map3Purchased = true;
		break;
	case 4:
		Map4Button.updateButtonTexture(purchasedTexture, onPurchasedTexture);
		Map4Button.setTexture(200, 0, 200, 50);
		Map4Button.active = false;
		Map4Purchased = true;
		break;
	}
}

void Shop::drawTo(sf::RenderWindow& window)
{
	//draw the background
	window.draw(BackgroundSprite);

	//draw the map 1 button
	Map1Button.DrawTo(window);

	//draw the map 2 button
	Map2Button.DrawTo(window);

	//draw the map 3 button
	Map3Button.DrawTo(window);

	//draw the map 4 button
	Map4Button.DrawTo(window);
}

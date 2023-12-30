#include "Button.h"

void Button::Load(std::string dir, std::string OnDir, sf::Vector2f Size, int NoPressindexX, int NoPressindexY, int NoPressSizeX, int NoPressSizeY)
{
	// Load the texture for the button
	if (ButtonTexture.loadFromFile(dir))
	{
		std::cout << "Loaded Button Texture" << std::endl;
		Sprite.setTexture(ButtonTexture);
		Sprite.setTextureRect(sf::Rect(NoPressindexX, NoPressindexY, NoPressSizeX, NoPressSizeY));
	}
	else
	{
		std::cout << "Failed to load Button Texture" << std::endl;
	}

	// Load the rollover texture for the button
	if (OnButtonTexture.loadFromFile(OnDir))
	{
		std::cout << "Loaded OnButton Texture" << std::endl;
	}
	else
	{
		std::cout << "Failed to load OnButton Texture" << std::endl;
	}

	// Set the size of the button
	button.setSize(Size);
	button.setFillColor(sf::Color::Transparent);
}

Button::Button()
{
}

void Button::switchState(int state)
{
	// Switches the state of the button
	switch (state)
	{
	case 0:
		Sprite.setTexture(ButtonTexture);
		ButtonState = 0;
		break;
	case 1:
		Sprite.setTexture(OnButtonTexture);
		ButtonState = 1;
		break;
	}
}

void Button::setTexture(int indexX, int indexY, int sizeX, int sizeY)
{
	// Sets the texture of the button
	Sprite.setTextureRect(sf::Rect(indexX, indexY, sizeX, sizeY));
}

void Button::updateButtonTexture(sf::Texture& texture, sf::Texture& onTexture)
{
	// Sets the texture of the button to the new textures
	ButtonTexture.update(texture);
	OnButtonTexture.update(onTexture);
}

void Button::MouseOver(sf::RenderWindow& window)
{
	// Checks if the mouse is over the button and changes the state accordingly
	if (active)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float btnX = button.getPosition().x;
		float btnY = button.getPosition().y;

		float btnXPosWidth = button.getPosition().x + button.getLocalBounds().width;
		float btnYPosHeight = button.getPosition().y + button.getLocalBounds().height;

		if (mouseX < btnXPosWidth && mouseX > btnX && mouseY < btnYPosHeight && mouseY > btnY)
		{
			switchState(1);
		}
		else
		{
			switchState(0);
		}
	}
}

void Button::setPosition(sf::Vector2f Position)
{
	// Sets the position of the button
	button.setPosition({ Position.x + 8, Position.y });
	Sprite.setPosition(Position);
}

void Button::DrawTo(sf::RenderWindow& window)
{
	// Draws the button
	window.draw(button);
	window.draw(Sprite);
}

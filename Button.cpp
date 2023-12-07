#include "Button.h"

void Button::Load(std::string dir, std::string OnDir, sf::Vector2f Size, int NoPressindexX, int NoPressindexY, int NoPressSizeX, int NoPressSizeY)
{
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

	if (OnButtonTexture.loadFromFile(OnDir))
	{
		std::cout << "Loaded OnButton Texture" << std::endl;
	}
	else
	{
		std::cout << "Failed to load OnButton Texture" << std::endl;
	}

	button.setSize(Size);
	button.setFillColor(sf::Color::Transparent);
}

Button::Button()
{
}

void Button::switchState(int state)
{
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
	Sprite.setTextureRect(sf::Rect(indexX, indexY, sizeX, sizeY));
}

void Button::MouseOver(sf::RenderWindow& window)
{
	if (active)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float btnX = button.getPosition().x;
		float btnY = button.getPosition().y;

		float btnXPosWidth = button.getPosition().x + button.getLocalBounds().width;
		float btnXPosHeight = button.getPosition().y + button.getLocalBounds().height;

		if (mouseX < btnXPosWidth && mouseX > btnX && mouseY < btnXPosHeight && mouseY > btnY)
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
	button.setPosition({ Position.x + 8, Position.y });
	Sprite.setPosition(Position);
}

void Button::DrawTo(sf::RenderWindow& window)
{
	window.draw(button);
	window.draw(Sprite);
}

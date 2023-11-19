#include "Button.h"

void Button::Load(std::string dir, std::string OnDir, sf::Vector2f Size)
{
	if (ButtonTexture.loadFromFile(dir))
    {
        std::cout << "Loaded Button Texture" << std::endl;
        Sprite.setTexture(ButtonTexture);
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

bool Button::isMouseOver(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float btnX = button.getPosition().x;
	float btnY = button.getPosition().y;

	float btnXPosWidth = button.getPosition().x + button.getLocalBounds().width;
	float btnXPosHeight = button.getPosition().y + button.getLocalBounds().height;

	if (mouseX < btnXPosWidth && mouseX > btnX && mouseY < btnXPosHeight && mouseY > btnY)
	{
		return true;
	}

	return false;
}

void Button::setPosition(sf::Vector2f Position)
{
	button.setPosition({Position.x+8, Position.y});
	Sprite.setPosition(Position);
}

void Button::switchState(int state)
{
	switch (state)
	{
	case 0:
		Sprite.setTexture(ButtonTexture);
		break;
	case 1:
		Sprite.setTexture(OnButtonTexture);
		break;
	}
}

void Button::DrawTo(sf::RenderWindow& window)
{
	window.draw(button);
	window.draw(Sprite);
}

#include "Button.h"

void Button::Initialize(std::string Text, sf::Vector2f Size, int charSize, sf::Color bgColor, sf::Color textColor)
{
	text.setString(Text);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);

	button.setSize(Size);
	button.setFillColor(bgColor);
}

void Button::Hide()
{
	text.setFillColor(sf::Color::Transparent);
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
	button.setPosition(Position);

	float xPos = (Position.x + button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2);
	float yPos = (Position.y + button.getLocalBounds().height / 2.5) - (text.getLocalBounds().height / 2);

	text.setPosition({xPos, yPos});
}

void Button::setFont(sf::Font& Font)
{
	text.setFont(Font);
}

void Button::setBackColor(sf::Color Color)
{
	button.setFillColor(Color);
}

void Button::DrawTo(sf::RenderWindow& window)
{
	window.draw(button);
	window.draw(text);
}

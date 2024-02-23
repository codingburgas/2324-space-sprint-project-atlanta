#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Button
{
public:
	Button()
	{

	}
	Button(string t, Vector2f size, int charSize, Color bgColor, Color textColor)
	{
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);

		button.setSize(size);
		button.setFillColor(bgColor);

	}

	void setFont(Font &font)
	{
		text.setFont(font);
	}

	void setBackColor(Color color, Color outline)
	{
		button.setFillColor(color);
		button.setOutlineColor(outline);
		button.setOutlineThickness(2);
	}

	void setTextColor(Color color)
	{
		text.setFillColor(color);
	}

	void setPosition(Vector2f pos)
	{
		button.setPosition(pos);
		float xPos = ((pos.x + button.getLocalBounds().width / 2.5) - (text.getLocalBounds().width / 2));
		float yPos = ((pos.y + button.getLocalBounds().height / 4) - (text.getLocalBounds().height / 2));
		text.setPosition({ xPos, yPos });
	}

	void drawTo(RenderWindow& window)
	{
		window.draw(button);
		window.draw(text);
	}

	bool isMouseOver(RenderWindow& window)
	{
		float mouseX = Mouse::getPosition(window).x;
		float mouseY = Mouse::getPosition(window).y;

		float btnPosX = button.getPosition().x;
		float btnPosY = button.getPosition().y;

		float btnXPosWidth = button.getPosition().x + button.getLocalBounds().width;
		float btnYPosHeight = button.getPosition().y + button.getLocalBounds().height;

		if (mouseX < btnXPosWidth && mouseX > btnPosX && mouseY < btnYPosHeight && mouseY > btnPosY)
		{
			return true;
		} else {
			return false;
		}
	}

private:
	RectangleShape button;
	Text text;
};
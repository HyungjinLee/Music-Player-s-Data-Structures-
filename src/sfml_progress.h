#pragma once
#include <SFML/Graphics.hpp>

class sfml_progress
{

	float X;
	float Y;
	float Width;
	float Heigh;
	float Progression;

	sf::RectangleShape BOX;
	sf::RectangleShape BAR;


public:

	sfml_progress()
	{

	}
	sfml_progress(float x, float y, float width, float heigh, sf::Color boxcolor, sf::Color barcolor)
	{
		this->create(x, y, width, heigh, boxcolor, barcolor);
	}

	~sfml_progress()
	{
		//BOX.~Shape();
		//BAR.~Shape();
	}

	void create(float x, float y, float width, float heigh, sf::Color boxcolor, sf::Color barcolor)
	{
		X = x;
		Y = y;
		Width = width;
		Heigh = heigh;
		Progression = 0;

		BOX.setFillColor(sf::Color(0, 0, 0, 0));
		BOX.setOutlineColor(boxcolor);
		BOX.setOutlineThickness(1);
		BAR.setFillColor(barcolor);

		BOX.setPosition(x, y);
		BAR.setPosition(x, y);

		BOX.setSize(sf::Vector2<float>(width, heigh));
		BAR.setSize(sf::Vector2<float>(0, heigh));

	}

	void setprogression(float p)
	{
		if (p>1)
		{
			p = 1;
		}
		if (p<0)
		{
			p = 0;
		}
		Progression = p;
	}

	void setbarcolor(sf::Color color_bar)
	{
		BAR.setFillColor(color_bar);
	}

	float getprogression()
	{
		return Progression;
	}

	void draw(sf::RenderWindow* mrw)
	{

		BAR.setSize(sf::Vector2<float>(Width*Progression, Heigh));
		if (Progression>0)
		{
			mrw->draw(BAR);
		}
		mrw->draw(BOX);
	}

};
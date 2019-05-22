#pragma once
#include <SFML\Graphics.hpp>

class sfml_slidecontrol
{
	float X;
	float Y;
	float Width;
	float Heigh;

	float Regulator;
	float Regulator_def;
	float Regulationsteps;

	sf::RectangleShape REGBOX;
	sf::Vertex REGLINE[2];
	sf::RectangleShape REGBAR;

	float WSW;
	float WSH;

	void internalupdate()
	{
		REGBAR.setPosition(X + Width*Regulator - Width / Regulationsteps*Regulator, Y);
	}

public:

	sfml_slidecontrol()
	{

	}

	sfml_slidecontrol(sf::RenderWindow* mrw, float x, float y, float width, float heigh, float default_regulation, float regulationsteps, sf::Color background_color, sf::Color box_color, sf::Color line_color, sf::Color slider_color)
	{
		this->create(mrw, x, y, width, heigh, default_regulation, regulationsteps, background_color, box_color, line_color, slider_color);
	}

	~sfml_slidecontrol()
	{
		//REGBOX.~Drawable();
		//REGBAR.~Drawable();
	}

	void create(sf::RenderWindow* mrw, float x, float y, float width, float heigh, float default_regulation, float regulationsteps, sf::Color background_color, sf::Color box_color, sf::Color line_color, sf::Color slider_color)
	{
		X = x;
		Y = y;
		Width = width;
		Heigh = heigh;
		WSW = mrw->getSize().x;
		WSH = mrw->getSize().y;

		if (default_regulation<0)
		{
			default_regulation = 0;
		}
		if (default_regulation>1)
		{
			default_regulation = 1;
		}
		if (regulationsteps<1)
		{
			regulationsteps = 1;
		}


		Regulator_def = default_regulation;
		Regulator = default_regulation;
		Regulationsteps = regulationsteps;

		REGBOX.setFillColor(background_color);
		REGBOX.setOutlineColor(box_color);
		REGBOX.setOutlineThickness(1);
		REGBOX.setPosition(x, y);
		REGBOX.setSize(sf::Vector2<float>(width, heigh));

		REGLINE[0] = sf::Vertex(sf::Vector2<float>(x, y + heigh / 2), line_color);
		REGLINE[1] = sf::Vertex(sf::Vector2<float>(x + width, y + heigh / 2), line_color);

		REGBAR.setFillColor(slider_color);
		REGBAR.setPosition(x + width*default_regulation - width / regulationsteps*default_regulation, y);
		REGBAR.setSize(sf::Vector2<float>(width / regulationsteps, heigh));



	}


	void eventupdate(sf::RenderWindow* mrw, sf::Event* event)
	{

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			float WFx = WSW / mrw->getSize().x;
			float WFy = WSH / mrw->getSize().y;

			if (sf::Mouse::getPosition(*mrw).x*WFx + Width / 30>X&&sf::Mouse::getPosition(*mrw).x*WFx - Width / 30<X + Width&&sf::Mouse::getPosition(*mrw).y*WFy>Y&&sf::Mouse::getPosition(*mrw).y*WFy<Y + Heigh)
			{
				Regulator = (sf::Mouse::getPosition(*mrw).x*WFx - X) / Width;
				if (Regulator<0)
				{
					Regulator = 0;
				}
				if (Regulator>1)
				{
					Regulator = 1;
				}
				REGBAR.setPosition(X + Width*Regulator - Width / Regulationsteps*Regulator, Y);
			}
		}


	}

	float getsliderfactor()
	{
		return Regulator;
	}
	float getsliderfactor_default()
	{
		return Regulator_def;
	}

	void setdefault()
	{
		Regulator = Regulator_def;
	}

	void setregulator(float regulation)
	{
		if (regulation<0)
		{
			regulation = 0;
		}
		if (regulation>1)
		{
			regulation = 1;
		}
		if (regulation<1)
		{
			regulation = 1;
		}
		Regulator = regulation;
		this->internalupdate();
	}

	void setsteps(float steps)
	{
		Regulationsteps = steps;
		this->internalupdate();
	}

	void draw(sf::RenderWindow* mrw)
	{
		mrw->draw(REGBOX);
		mrw->draw(REGLINE, 2, sf::Lines);
		mrw->draw(REGBAR);
	}


};


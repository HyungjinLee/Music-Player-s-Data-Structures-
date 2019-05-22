#pragma once
#include <iostream>
#include "Screen.h"
#include "MusicType.h"
#include <SFML/Graphics.hpp>
#include "sfml_progress.h"
#include "sfml_slider.h"

class screen_0 : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool paused;
public:
	screen_0(void);
	virtual int Run(sf::RenderWindow &App, sf::Music &music);
};

screen_0::screen_0(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	paused = false;
}

int screen_0::Run(sf::RenderWindow &App, sf::Music &music)
{

	sf::Event Event;
	bool Running = true;
	sf::Texture Texture1;
	sf::Texture Texture2;
	sf::Texture Texture3;
	sf::Texture Texture4;

	sf::Sprite Sprite;
	

	int alpha = 0;
	int count = 0;

	sf::Font Font;
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;
	
	int menu = 0;
	float PX = 0.01;
	int duration = music.getDuration().asSeconds();	// get duration
	
	auto newPos = music.getPlayingOffset();


	// Creation of the objects
	sfml_progress PROG(50, 400, 300, 20, sf::Color(255, 255, 255, 255), sf::Color(0, 255, 0, 255));
	sfml_slidecontrol Slider1(&App, 50, 300, 600, 20, 0.5, 100, sf::Color(230, 230, 230, 255), sf::Color::Black, sf::Color(100, 100, 255, 255), sf::Color(80, 80, 80, 255));
	
	if (!Texture1.loadFromFile("presentation.png"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}

	if (!Texture2.loadFromFile("presentation2.png"))
	{
		std::cerr << "Error loading presentation2.gif" << std::endl;
		return (-1);
	}

	if (!Texture3.loadFromFile("presentation3.png"))
	{
		std::cerr << "Error loading presentation3.gif" << std::endl;
		return (-1);
	}
	
	if (!Texture4.loadFromFile("presentation4.png"))
	{
		std::cerr << "Error loading presentation4.gif" << std::endl;
		return (-1);
	}

	
	if (!Font.loadFromFile("Nanum.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
		return (-1);
	}

	Menu1.setFont(Font);
	Menu1.setCharacterSize(20);
	Menu1.setString("Pause");
	Menu1.setPosition({ 280.f, 160.f });

	Menu2.setFont(Font);
	Menu2.setCharacterSize(20);
	Menu2.setString("Stop");
	Menu2.setPosition({ 280.f, 220.f });

	Menu3.setFont(Font);
	Menu3.setCharacterSize(20);
	Menu3.setString("Resume");
	Menu3.setPosition({ 280.f, 160.f });

	if (paused)
	{
		alpha = alpha_max;
	}

	while (Running)
	{
	
		sf::Event event;
		sf::Text sDuration;

		newPos = music.getPlayingOffset();

		char temp[50];
		int cursec = newPos.asSeconds();
		sprintf(temp,"%02d:%02d/%02d:%02d", cursec / 60, cursec % 60, duration / 60, duration % 60);

		sDuration.setFont(Font);
		sDuration.setString(temp);
		sDuration.setCharacterSize(10);
		sDuration.setPosition(10.f, 50.f);
		sDuration.setFillColor(sf::Color::Red);
		

		if (!paused && cursec > 0)
		{
			PROG.setprogression(PX);

			PX =  ((cursec/(double)duration)*100)/100;

			if (PX>1)
			{
				PX = 0.01;
			}

			switch (count % 15)
			{
			case 0:
				Sprite.setTexture(Texture1);
				Sprite.setColor(sf::Color(0, 0, 0, alpha));
				break;

			case 2:
				Sprite.setTexture(Texture2);
				Sprite.setColor(sf::Color(0, 0, 0, alpha));
				break;

			case 3:
				Sprite.setTexture(Texture2);
				Sprite.setColor(sf::Color(0, 0, 0, alpha));
				break;
			
			case 4:
				Sprite.setTexture(Texture1);
				Sprite.setColor(sf::Color(0, 0, 0, alpha));
				break;

			case 5:
				Sprite.setTexture(Texture2);
				Sprite.setColor(sf::Color(0, 0, 0, alpha));
				break;
			case 6:
				Sprite.setTexture(Texture2);
				Sprite.setColor(sf::Color(0, 0, 0, alpha));
				break;

			default:
				Sprite.setTexture(Texture3);
				Sprite.setColor(sf::Color(0, 0, 0, alpha));
				break;
			}

		}

		//Verifying events
		while (App.pollEvent(Event))
		{

			Slider1.eventupdate(&App, &event);

	
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}

			newPos = music.getPlayingOffset();
			
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Up:
					menu = 0;
					break;
				case sf::Keyboard::Down:
					menu = 1;
					break;

				case sf::Keyboard::Right:
					newPos = music.getPlayingOffset() + sf::seconds(5);
					if (newPos.asSeconds() >= duration) newPos = sf::seconds(duration);
					music.setPlayingOffset(sf::Time(newPos));
					break;

				case sf::Keyboard::Left:
					newPos = music.getPlayingOffset() - sf::seconds(5);
					if (newPos.asSeconds() <= 0.0f) newPos = sf::seconds(0);
					music.setPlayingOffset(sf::Time(newPos));
					break;
				case sf::Keyboard::Return: // Enter
					if (menu == 0)
					{
						//Let's get play !
						if (paused)
						{
							music.play();
							paused = false;
						}
						else
						{
							music.pause();
							paused = true;
						}
					}
					else
					{
						//Let's get work...
						return (-1);
					}
					break;
				default:
					break;
				}
			}
		}

		//When getting at alpha_max, we stop modifying the sprite
		if (alpha<alpha_max)
		{
			alpha++;
		}

		Sprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
		if (menu == 0)	// menu 1 selected
		{
			Menu1.setColor(sf::Color(255, 0, 0, 255));
			Menu2.setColor(sf::Color(255, 255, 255, 255));
			Menu3.setColor(sf::Color(255, 0, 0, 255));
		}
		else // menu 2 selected
		{
			Menu1.setColor(sf::Color(255, 255, 255, 255));
			Menu2.setColor(sf::Color(255, 0, 0, 255));
			Menu3.setColor(sf::Color(255, 255, 255, 255));
		}

		//Clearing screen

		App.clear();
		//Drawing
		App.draw(Sprite);
		App.draw(sDuration);

		PROG.draw(&App);


		if (alpha == alpha_max)
		{
			if (paused)
			{
				App.draw(Menu3);
			}
			else
			{
				App.draw(Menu1);
			}
			App.draw(Menu2);
		}

		count++;
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}

// MonitorsDeclandH.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>
#include <thread>
#include "player.h"
#include "monitor.h"

////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

Monitor* monitor = new Monitor();
sf::Text displayText;

void Fetch()
{
	std::string text;
	monitor->Fetch(text);
	std::cout << text << std::endl;
	displayText.setString(text);
}


int main()
{
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(960, 640, 32), "SFML First Program");
	bool increaseSpeed = false;
	//load a font
	sf::Font font;
	font.loadFromFile("arial.ttf");

	Player* player = new Player();

	displayText.setFont(font);
	displayText.setPosition(20, 20);
	displayText.setString("");
	//displayText.setColor(sf::Color::Blue);

	//std::thread t1;
	sf::Thread thread(&Fetch);

	sf::Clock clock;
	clock.restart();

	// Start game loop 
	while (window.isOpen())
	{
		// Process events 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// Close window : exit 
			if (Event.type == sf::Event::Closed)
				window.close();

			// Escape key : exit 
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();

			////right
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Q))
			{
				increaseSpeed = true;
				monitor->Deposit("speed increased");
				
			}

			//left
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::W))
			{
				increaseSpeed = false;
				monitor->Deposit("speed decreased");
				
			}

		}

		if (clock.getElapsedTime().asSeconds() > 0.5)
		{
			if (monitor->StringAdded() == true)
				thread.launch();
			else std::cout << "Nothing added to Buffer " << std::endl;
			clock.restart();
		}
		if (!increaseSpeed)
		{
			player->Move(.005f);
			displayText.setColor(sf::Color::Blue);
		}
		else if (increaseSpeed)
		{
			player->Move(.01f);
			displayText.setColor(sf::Color::Red);
		}
		
		window.clear();
		player->Draw(window);
		window.draw(displayText);

		
		window.display();

	} 

	return EXIT_SUCCESS;
}
//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}


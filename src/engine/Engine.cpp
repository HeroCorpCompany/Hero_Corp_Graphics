#include "Engine.h"

const sf::Time Engine::m_timePerFrame = sf::seconds(0.00001);

Engine::Engine()
: m_window(sf::VideoMode(650, 650), "Random Noise")
{
}

void Engine::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		
		while (timeSinceLastUpdate > m_timePerFrame)
		{
			timeSinceLastUpdate -= m_timePerFrame;
			update();
		}

		render();
	}
}

void Engine::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();
	}
}

void Engine::update()
{
    // What you want to update
}

void Engine::render()
{
	m_window.clear();
	// What you want to display
	m_window.display();
}

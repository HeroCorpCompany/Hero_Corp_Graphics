#include "Engine.h"

const sf::Time Engine::m_timePerFrame = sf::seconds(1.f/FPS);

Engine::Engine()
: m_window(sf::VideoMode(SIZE_SCREEN_X, SIZE_SCREEN_Y), "Hero Corp")
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
		switch(event.type)
		{
			case sf::Event::MouseButtonPressed:
				handleMouseInput(event.mouseButton.button);
				break;

			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::Escape){m_window.close();}
				break;

			case sf::Event::Closed:
				m_window.close();
				break;
				
			default:
				break;
		}
	}
}

void Engine::update()
{
    m_world.update(sf::Mouse::getPosition(m_window));
}

void Engine::render()
{
	m_window.clear();
	m_window.draw(m_world);
	m_window.display();
}

void Engine::handleMouseInput(sf::Mouse::Button mouse)
{
	if(mouse == sf::Mouse::Left) 
	{ 
		m_world.setIdSelected(deduceLocationIDFromMousePosition());
	}
}

int Engine::deduceLocationIDFromMousePosition() const
{
	int x = int(sf::Mouse::getPosition(m_window).x*SIZE_TABLE_X/(SIZE_SCREEN_X - SIZE_MENU));
	int y = int(sf::Mouse::getPosition(m_window).y*SIZE_TABLE_Y/SIZE_SCREEN_Y);
	
	std::vector<AbstractLocation*> locations = m_world.getLocations();

	int id = 0;

	for (std::size_t i = 0; i < locations.size(); ++i)
	{
		if (locations[i]->getPosition() == sf::Vector2i(x, y))
		{
			id = locations[i]->getID();
			break;
		}
	}

	return id;
}
#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../business/World.h"

class Engine
{
public :
	
	Engine();
	void run();

private :
	
	void processEvents();
	void update();
	void render();
	
private :
	sf::RenderWindow m_window;
	static const sf::Time m_timePerFrame;

	World m_world;
};

#endif //ENGINE_H

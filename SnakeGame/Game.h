#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow &window;

public:
	Game(sf::RenderWindow& w);
	~Game() {};

	void Run();
};


#pragma once
#include <SFML/Graphics.hpp>
#include "Place.h"

enum Directions {
	LEFT,
	RIGHT,
	TOP,
	DOWN
};

class Game
{
private:
	sf::RenderWindow& window;
	Place places[10][10];
	Directions dirs = RIGHT;

public:
	Game(sf::RenderWindow& w);
	~Game() {};

	void Run();
	void DrawPlaces();
};


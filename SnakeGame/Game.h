#pragma once
#include <SFML/Graphics.hpp>
#include "Place.h"
#include <utility>
#include <stdio.h>

using namespace std;

class Game
{
private:
	enum Directions {
		LEFT,
		RIGHT,
		TOP,
		DOWN
	};
	sf::RenderWindow *window;
	Place places[13][13];
	Directions dirs = RIGHT;
	pair<int, int> snakePos;

public:
	Game(sf::RenderWindow* w);
	~Game() {};

	void Run();
	void DrawPlaces();
	void Snake();
};


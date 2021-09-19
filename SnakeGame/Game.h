#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Place.h"
#include <utility>
#include <vector>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class Game
{
private:
	bool gameRunning = true;
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
	pair<int, int> fruitPos;
	vector<pair<int, int>> snakeHeadPositions;
	int snakeLenght = 1;
	bool FruitAvailableToSpawn = true;

	sf::Font font;
	sf::Text gameOver = sf::Text("Game over!", font, 30);
	sf::Text restartGame = sf::Text("Press R to restart!", font, 20);
	sf::RectangleShape restartButton = sf::RectangleShape(sf::Vector2f(145.0f, 25.0f));

	void DrawPlaces();
	void Snake();
	void SpawnFruit();
	void ClearTable();
	void CollectFruit();
	void LoseConditions();

public:
	Game(sf::RenderWindow* w, sf::Font f);
	~Game() {};

	void Run();

};


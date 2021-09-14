#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	const int screenWidth = 260;
	const int screenHeight = 260;
	sf::RenderWindow w(sf::VideoMode(screenWidth, screenHeight), "Snake");
	w.setFramerateLimit(10);

	Game game(&w);
	game.Run();

	return 0;
}
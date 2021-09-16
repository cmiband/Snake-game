#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	const int screenWidth = 260;
	const int screenHeight = 260;
	sf::RenderWindow w(sf::VideoMode(screenWidth, screenHeight), "Snake");
	w.setFramerateLimit(30);

	sf::Font f;
	if (!f.loadFromFile("BebasNeue-Regular.ttf")) {
		return EXIT_FAILURE;
	}

	Game game(&w,f);
	game.Run();

	return 0;
}
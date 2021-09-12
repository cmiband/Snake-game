#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	sf::RenderWindow w(sf::VideoMode(180, 180), "Snake");

	Game game(w);
	Game* gameptr = &game;

	gameptr->Run();

	return 0;
}
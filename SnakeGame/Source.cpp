#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	sf::RenderWindow w(sf::VideoMode(500, 500), "Mikoshi");

	Game game(w);
	Game* gameptr = &game;

	gameptr->Run();

	return 0;
}
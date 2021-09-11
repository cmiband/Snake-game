#include "Game.h"

Game::Game(sf::RenderWindow& w) : window(w) {
	
}

void Game::Run() {
	while (window.isOpen()) {
		sf::Event e;

		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}

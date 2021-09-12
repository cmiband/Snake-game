#include "Game.h"

Game::Game(sf::RenderWindow& w) : window(w) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Place p(sf::Vector2f(j * 20.0f, i * 20.0f));
			places[i][j] = p;
		}
	}
}

void Game::DrawPlaces() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			window.draw(places[i][j].getShape());
		}
	}
}

void Game::Run() {
	while (window.isOpen()) {
		sf::Event e;

		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}

			window.clear();

			DrawPlaces();

			window.display();
		}
	}
}

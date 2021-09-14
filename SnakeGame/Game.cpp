#include "Game.h"

Game::Game(sf::RenderWindow* w) : window(w) {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			Place p(sf::Vector2f(j * 20.0f, i * 20.0f));
			places[i][j] = p;
		}
	}
}

void Game::DrawPlaces() {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			window->draw(places[i][j].getShape());
		}
	}
}

void Game::Snake() {
	places[snakePos.first][snakePos.second].SetSnakeCover(false);
	places[snakePos.first][snakePos.second].ChangeColor();
	switch (dirs)
	{
	case Game::LEFT:
		snakePos.second--;
		break;
	case Game::RIGHT:
		snakePos.second++;
		break;
	case Game::TOP:
		snakePos.first--;
		break;
	case Game::DOWN:
		snakePos.first++;
		break;
	default:
		break;
	}
}

void Game::Run() {
	snakePos.first = 4;
	snakePos.second = 4;
	sf::Clock clock;

	while (window->isOpen()) {
		sf::Event e;

		while (window->pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window->close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				dirs = Game::TOP;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				dirs = Game::DOWN;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				dirs = Game::LEFT;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				dirs = Game::RIGHT;
			}

			sf::Time elapsedRaw = clock.getElapsedTime();
			int elapsed = elapsedRaw.asMilliseconds();

			window->clear();
			
			printf("%d\n", elapsed);
			if (elapsed >= 300) {
				Snake();
				places[snakePos.first][snakePos.second].SetSnakeCover(true);
				places[snakePos.first][snakePos.second].ChangeColor();
				clock.restart();
			}

			DrawPlaces();

			window->display();
		}
	}
}

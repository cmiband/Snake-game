#include "Game.h"

Game::Game(sf::RenderWindow* w, sf::Font f) : window(w), font(f) {
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
	if (snakeLenght > 1) {
		int l = (int)snakeHeadPositions.size();
		places[snakePos.first][snakePos.second].SetSnakeCover(true);
		places[snakePos.first][snakePos.second].ChangeColor();
		for (int i = 1; i < snakeLenght; i++) {
			places[snakeHeadPositions[l - i].first][snakeHeadPositions[l - i].second].SetSnakeCover(true);
			places[snakeHeadPositions[l - i].first][snakeHeadPositions[l - i].second].ChangeColor();
		}
	}
	if (snakeLenght <= 1) {
		places[snakePos.first][snakePos.second].SetSnakeCover(true);
		places[snakePos.first][snakePos.second].ChangeColor();
	}
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

void Game::LoseConditions() {
	if (snakePos.first <= 0) {
		if (dirs == Game::TOP) {
			gameRunning = false;
		}
	}
	if (snakePos.first >= 12) {
		if (dirs == Game::DOWN) {
			gameRunning = false;
		}
	}
	if (snakePos.second >= 12) {
		if (dirs == Game::RIGHT) {
			gameRunning = false;
		}
	}
	if (snakePos.second <= 0) {
		if (dirs == Game::LEFT) {
			gameRunning = false;
		}
	}
}

void Game::SpawnFruit() {
	if (FruitAvailableToSpawn) {
		int randx = rand() % 12;
		int randy = rand() % 12;
		if ((randx != snakePos.second) && (randy != snakePos.first)) {
			places[randx][randy].SetFruitCover(true);
			places[randx][randy].ChangeColor();
			fruitPos.first = randx;
			fruitPos.second = randy;
		}
		FruitAvailableToSpawn = false;
	}
}

void Game::CollectFruit() {
	if ((fruitPos.first == snakePos.first) && (fruitPos.second == snakePos.second)) {
		places[fruitPos.first][fruitPos.second].SetFruitCover(false);
		places[fruitPos.first][fruitPos.second].ChangeColor();
		snakeLenght++;
		FruitAvailableToSpawn = true;
	}
}

void Game::Run() {
	snakePos.first = 4;
	snakePos.second = 4;
	snakeHeadPositions.push_back(make_pair(snakePos.first,snakePos.second));
	sf::Clock clock;
	float elapsed;
	
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

			elapsed = clock.getElapsedTime().asSeconds();

			window->clear();
			
			DrawPlaces();
			SpawnFruit();
			if (gameRunning) {
				if (elapsed >= 0.7f) {
					LoseConditions();
					Snake();
					CollectFruit();
					places[snakePos.first][snakePos.second].SetSnakeCover(true);
					places[snakePos.first][snakePos.second].ChangeColor();
					snakeHeadPositions.push_back(make_pair(snakePos.first, snakePos.second));
					clock.restart();
				}
			}
			else {
				window->draw(gameOver);
			}

			window->display();
		}
	}
}

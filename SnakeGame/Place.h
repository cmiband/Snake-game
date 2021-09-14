#pragma once
#include <SFML/Graphics.hpp>

class Place
{
private:
	sf::RectangleShape shp = sf::RectangleShape(sf::Vector2f(20.0f, 20.0f));
	bool isPartOfSnake = false;

public:
	Place() {
		shp.setFillColor(sf::Color::Green);
	};
	Place(sf::Vector2f pos) {
		shp.setPosition(pos);
		shp.setFillColor(sf::Color::Green);
	};
	~Place() {};

	sf::RectangleShape getShape() { return shp; }
	void SetPos(sf::Vector2f pos) {
		shp.setPosition(pos);
	}

	bool GetSnakeCover() {
		return isPartOfSnake;
	}

	void SetSnakeCover(bool val) {
		isPartOfSnake = val;
	}

	void ChangeColor() {
		if (isPartOfSnake) {
			shp.setFillColor(sf::Color::Red);
		}
		else {
			shp.setFillColor(sf::Color::Green);
		}
	}
};


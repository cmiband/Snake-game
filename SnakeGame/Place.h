#pragma once
#include <SFML/Graphics.hpp>

class Place
{
private:
	sf::RectangleShape shp = sf::RectangleShape(sf::Vector2f(20.0f, 20.0f));
	bool isPartOfSnake = false;
	bool isPickableFruit = false;

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
		if (isPartOfSnake || isPickableFruit) {
			shp.setFillColor(sf::Color::Red);
		}
		else {
			shp.setFillColor(sf::Color::Green);
		}
	}

	bool GetFruitCover() {
		return isPickableFruit;
	}

	void SetFruitCover(bool val) {
		isPickableFruit = val;
	}
};


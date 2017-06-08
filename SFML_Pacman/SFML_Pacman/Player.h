#include <SFML\Graphics.hpp>
#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

class Player {
	public:
		Player(Map* mapa);
		~Player();

		void draw(sf::RenderWindow* window);
		void rotate(float rotation);
		void updateLogic();

		void setDirection(sf::Vector2f direction);


	private:
		bool collidesWithWall(sf::Vector2f pos);

		sf::Sprite sprite;
		sf::Texture texture;

		sf::Vector2f dir, dirBuffer;
		Map* map;
};

Player::Player(Map* mapa) {
	texture.loadFromFile("Recursos/pacman.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	sprite.setPosition(sf::Vector2f(264, 24));
	sprite.setOrigin(sf::Vector2f(8, 8));

	map = mapa;

	dir = sf::Vector2f(0, 0);
	dirBuffer = sf::Vector2f(0, 0);
}

Player::~Player() {

}

inline void Player::draw(sf::RenderWindow* window) {
	window->draw(sprite);
}

inline void Player::rotate(float rotation) {
	sprite.setRotation(rotation);
}

inline void Player::setDirection(sf::Vector2f direction){
	dirBuffer = direction;
}

inline bool Player::collidesWithWall(sf::Vector2f pos) {
	return
		map->getTile(pos + sf::Vector2f(-8, -8)) == 1 ||
		map->getTile(pos + sf::Vector2f( 7, -8)) == 1 ||
		map->getTile(pos + sf::Vector2f( 7,  7)) == 1 ||
		map->getTile(pos + sf::Vector2f(-8,  7)) == 1;
}

inline void Player::updateLogic() {

	if (!collidesWithWall(sprite.getPosition() + sf::Vector2f(dirBuffer.x * 8, dirBuffer.y * 8))) {
		dir = dirBuffer;
		sprite.setRotation(atan2(dir.y, dir.x) * (180.0 / M_PI));
	}

	if (collidesWithWall( sprite.getPosition() + sf::Vector2f(dir.x, dir.y) )) {
		dir = sf::Vector2f(0, 0);
	}

	sprite.move( sf::Vector2f(
		dir.x / 2,
		dir.y / 2
	));

	sprite.setPosition( sf::Vector2f(
		(float)fmod(sprite.getPosition().x, 448),
		(float)fmod(sprite.getPosition().y, 496)
	));

	if (sprite.getPosition().x < 0) {
		sprite.setPosition(sf::Vector2f(448, sprite.getPosition().y));
	}

	if (map->getTile(sprite.getPosition()) == 2) {
		map->removeTile(sprite.getPosition());
	}
}
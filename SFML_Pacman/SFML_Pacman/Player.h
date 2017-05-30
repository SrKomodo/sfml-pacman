#include <SFML\Graphics.hpp>
#pragma once

class Player {
	public:
		Player();
		~Player();

		void draw(sf::RenderWindow& window);
		void move(sf::Vector2i direction);
		void rotate(int rotation);
		void updateLogic(sf::Time deltaTime, Mapa& map);

	private:
		sf::Sprite sprite;
		sf::Texture texture;

		sf::Vector2f vel;
};

Player::Player() {
	texture.loadFromFile("Recursos/pacman.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	sprite.setPosition(sf::Vector2f(232, 376));
	sprite.setOrigin(sf::Vector2f(8, 8));

	vel = sf::Vector2f(0, 0);

}

Player::~Player() {

}

inline void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

inline void Player::move(sf::Vector2i direction) {
	vel = (sf::Vector2f)direction;
}

inline void Player::rotate(int rotation) {
	sprite.setRotation(rotation);
}

inline void Player::updateLogic(sf::Time deltaTime, Mapa& map) {

	//sprite.move(sf::Vector2f(vel.x * 16, vel.y * 16));

	/*if (map.getTile(sprite.getPosition()) == 1) {
		sprite.move(sf::Vector2f(-vel.x * 16, -vel.y * 16));
	}*/

	//vel = sf::Vector2f(0, 0);

	sprite.move( sf::Vector2f(
		vel.x * deltaTime.asMilliseconds() / 5,
		vel.y * deltaTime.asMilliseconds() / 5
	));

	sf::Vector2f pos(sprite.getPosition());

	if (
		map.getTile( sf::Vector2f( pos.x - 7 , pos.y - 7 )) == 1 ||
		map.getTile( sf::Vector2f( pos.x - 7 , pos.y + 7 )) == 1 ||
		map.getTile( sf::Vector2f( pos.x + 7 , pos.y - 7 )) == 1 ||
		map.getTile( sf::Vector2f( pos.x + 7 , pos.y + 7 )) == 1
	) {
		sprite.move(sf::Vector2f(
			-vel.x * deltaTime.asMilliseconds() / 5,
			-vel.y * deltaTime.asMilliseconds() / 5
		));
	}

	if (map.getTile( sprite.getPosition()) == 2) {
		map.removeTile(sprite.getPosition());
	}

	sprite.setPosition( sf::Vector2f(
		fmod(sprite.getPosition().x, 448),
		fmod(sprite.getPosition().y, 496)
	));

	if (sprite.getPosition().x < 0) {
		sprite.setPosition(sf::Vector2f(448, sprite.getPosition().y));
	}
}
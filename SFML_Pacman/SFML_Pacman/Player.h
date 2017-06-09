#include "Entity.h"

#define _USE_MATH_DEFINES
#include <math.h>

class Player : public Entity {

	using Entity::Entity;

public:
	void updateLogic();
	void onDirChange();
};

inline void Player::updateLogic() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		setDirection(sf::Vector2f(-1, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		setDirection(sf::Vector2f(1, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		setDirection(sf::Vector2f(0, -1));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		setDirection(sf::Vector2f(0, 1));
	}
	
	mapCollision();
	if (map->getTile(sprite.getPosition()) == 2) {
		map->removeTile(sprite.getPosition());
	}
}

inline void Player::onDirChange() {
	sprite.setRotation(atan2(dir.y, dir.x) * (180.0 / M_PI));
}
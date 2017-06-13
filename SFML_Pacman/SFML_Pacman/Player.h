#include "Entity.h"

#define _USE_MATH_DEFINES
#include <math.h>

class Player : public Entity {
	using Entity::Entity;

public:
	Player(Map* mapToLoad, std::string path, sf::Vector2f position);
	
	void updateLogic();
	void onDirChange();

private:
	float animationFrame;
	int puntaje = 0;
};

Player::Player(Map* mapToLoad, std::string path, sf::Vector2f position) : Entity(mapToLoad, path, position) {
	sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	animationFrame = 0;
}

inline void Player::updateLogic() {
	
	sprite.setTextureRect(sf::IntRect( floorf(animationFrame / 16.f) * 16, 0, 16, 16));
	animationFrame += 4.f;
	animationFrame = fmod(animationFrame, 16.f * 6.f);

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
		puntaje++;
		std::cout << puntaje << std::endl;
	}
}

inline void Player::onDirChange() {
	sprite.setRotation(atan2(dir.y, dir.x) * (180.f / (float)M_PI));
}
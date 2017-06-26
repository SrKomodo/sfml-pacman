#include <iostream>
#include <random>
#include <SFML\Graphics.hpp>

#include "Map.h"
#include "Player.h"
#include "Monster.h"

int main() {

	sf::Clock clock;
	sf::Time accumulator = sf::Time::Zero;
	sf::Time ups = sf::seconds(1.f / 60.f);

	sf::RenderWindow window(sf::VideoMode(448,496), "Pacman");

	Map map("Recursos/map.txt");

	Player player = Player(&map, "Recursos/pacman.png", sf::Vector2f(224, 376));

	Monster monster = Monster(&map, "Recursos/ghost.png", sf::Vector2f(232, 184));

	sf::Event event;

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code) {

				}
				break;
			}
		}

		while (accumulator > ups) {
			accumulator -= ups;
			player.updateLogic(monster.getPos());
			monster.updateLogic();
		}

		window.clear();
		
		map.draw(&window);
		player.draw(&window);

		monster.draw(&window);

		window.display();
		accumulator += clock.restart();

	}

	return EXIT_SUCCESS;
}
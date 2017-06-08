#include <iostream>
#include <random>
#include <SFML\Graphics.hpp>

#include "Map.h"
#include "Player.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(448,496), "Pacman");

	Map map("Recursos/map.txt");

	Player player = Player(&map);

	sf::Event event;
	sf::Clock clock;
	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code) {

				case sf::Keyboard::Right:
					player.setDirection(sf::Vector2f(1, 0));
					break;
				case sf::Keyboard::Left:
					player.setDirection(sf::Vector2f(-1, 0));
					break;
				case sf::Keyboard::Up:
					player.setDirection(sf::Vector2f(0, -1));
					break;
				case sf::Keyboard::Down:
					player.setDirection(sf::Vector2f(0, 1));
					break;

				}
				break;
			}
		}

		if ( clock.getElapsedTime().asSeconds() >= 1 / 60 ) {
			player.updateLogic();
		}

		window.clear();
		
		map.draw(&window);

		player.draw(&window);

		window.display();

	}

	return EXIT_SUCCESS;
}
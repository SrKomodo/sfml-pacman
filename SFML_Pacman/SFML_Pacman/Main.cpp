#include <iostream>
#include <random>
#include <SFML\Graphics.hpp>

#include "Map.h"
#include "Player.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(448,496), "Pacman");

	Map map("Recursos/map.txt");

	Player player = Player(&map, "Recursos/pacman.png", sf::Vector2f(264, 24));

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
#include <iostream>
#include <SFML\Graphics.hpp>

#include "Mapa.h"
#include "Player.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(448,496), "Pacman");

	Mapa mapa("Recursos/mapa.txt");
	Player player = Player();

	sf::Event event;
	sf::Clock clock;
	while (window.isOpen()) {
		sf::Time deltaTime = clock.restart();

		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code) {

				case sf::Keyboard::Right:
					player.move(sf::Vector2i(1, 0));
					player.rotate(0);
					break;
				case sf::Keyboard::Left:
					player.move(sf::Vector2i(-1, 0));
					player.rotate(180);
					break;
				case sf::Keyboard::Up:
					player.move(sf::Vector2i(0, -1));
					player.rotate(-90);
					break;
				case sf::Keyboard::Down:
					player.move(sf::Vector2i(0, 1));
					player.rotate(90);
					break;

				}
				break;
			}
		}
		window.clear();
		
		mapa.draw(window);

		player.updateLogic(deltaTime, mapa);
		player.draw(window);

		window.display();

	}

	return EXIT_SUCCESS;
}
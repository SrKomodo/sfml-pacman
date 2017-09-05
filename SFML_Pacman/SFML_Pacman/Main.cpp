#include <iostream>
#include <SFML\Graphics.hpp>

int main() {

	sf::Clock clock;
	sf::Time accumulator = sf::Time::Zero;
	sf::Time ups = sf::seconds(1.f / 60.f);

	sf::RenderWindow window(sf::VideoMode(448,496), "Pacman");

	sf::Event event;

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			}
		}

		while (accumulator > ups) {
			// update logic	
		}

		window.clear();
		
		// draw

		window.display();
		accumulator += clock.restart();

	}

	return EXIT_SUCCESS;
}
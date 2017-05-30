#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Mapa {
	public:
		Mapa(std::string filePath);
		~Mapa();

		void draw(sf::RenderWindow& window);
		int getTile(sf::Vector2f pos);
		void removeTile(sf::Vector2f pos);

	private:
		int nivel[28][31] = { 0 };
		sf::Texture texture;
		sf::RectangleShape wall = sf::RectangleShape(sf::Vector2f(16,16));
};

Mapa::Mapa(std::string filePath) {

	std::ifstream archivo(filePath);

	sf::Vector2i contador = sf::Vector2i(0, 0);
	while ( !archivo.eof() ) {
		char bloque;
		archivo >> bloque;
		nivel[contador.x][contador.y] = bloque - '0';
		if ( archivo.peek() == '\n') {
			contador.x++;
			contador.y = 0;
		}
		else {
			contador.y++;
		}
	}

	texture = sf::Texture();
	texture.loadFromFile("Recursos/tileMap.png");
	wall.setTexture( &texture );
}

Mapa::~Mapa() {

}

inline void Mapa::draw(sf::RenderWindow& window) {

	for (int x = 0; x < 28; x++) {
		for (int y = 0; y < 31; y++) {

			if ( nivel[x][y] != 0 ) {
				wall.setPosition((float)x * 16, (float)y * 16);
				wall.setTextureRect(sf::IntRect((nivel[x][y] - 1) * 16, 0, 16, 16));
				window.draw(wall);
			}

		}
	}

}

inline int Mapa::getTile(sf::Vector2f pos) {
	return nivel[(int)pos.x / 16][(int)pos.y / 16];
}

inline void Mapa::removeTile(sf::Vector2f pos) {
	nivel[(int)pos.x / 16][(int)pos.y / 16] = 0;
}

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main() {
	sf::Window window;
	
	window.create(sf::VideoMode(800, 600), "Trevinklar");
	sf::sleep(sf::seconds(2));
	window.close();
}

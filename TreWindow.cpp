#include "TreWindow.h"

#include <SFML/Window/Event.hpp>
namespace tre {
	
	TreWindow::TreWindow() :
		sf::RenderWindow() {
		create(sf::VideoMode(800, 600), "Trevinklar");
	}
	
	bool TreWindow::update() {
		sf::Event ev;
		while(pollEvent(ev)) {
			switch(ev.type) {
				case sf::Event::Closed:
					close();
					return false;
				default: break;			
			}
		}
		return true;
	}
};

#ifndef TRE_TRE_WINDOW_H
#define TRE_TRE_WINDOW_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Box2D/Box2D.h"

namespace tre {
	class TreWindow : public sf::RenderWindow {
	public:
		TreWindow();
		
		bool update();

	private:
		b2Body* m_ground;
		b2Body* m_triangle;
		b2World m_world;
	};
};
#endif

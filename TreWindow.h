#ifndef TRE_TRE_WINDOW_H
#define TRE_TRE_WINDOW_H

#include <SFML/Graphics/RenderWindow.hpp>

namespace tre {
	class TreWindow : public sf::RenderWindow {
		public:
		TreWindow();
		
		bool update();
	};
};
#endif

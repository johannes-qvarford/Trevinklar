#ifndef TRE_TRE_WINDOW
#define TRE_TRE_WINDOW

#include <SFML/Graphics/RenderWindow.hpp>

namespace tre {
	class TreWindow : public sf::RenderWindow {
		public:
		TreWindow();
		
		bool update();
	};
};
#endif

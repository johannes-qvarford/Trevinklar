#include "TreWindow.h"

#include <SFML/Window/Event.hpp>
#include <SFML/System/Sleep.hpp>
namespace tre {

	constexpr auto PHYSICS_VELOCITY_ITERATIONS = 6;
	constexpr auto PHYSICS_POSITION_ITERATIONS = 2;
	constexpr auto PHYSICS_TIMESTEP = 1.f / 60.f;
	
	TreWindow::TreWindow() :
		sf::RenderWindow(),
		m_world(b2Vec2(0.f, -10.f)) {
		create(sf::VideoMode(800, 600), "Trevinklar");

		b2BodyDef groundDef;
		groundDef.position.Set(0.f, -10.f);
		m_ground = m_world.CreateBody(&groundDef);
		b2PolygonShape groundShape;
		groundShape.SetAsBox(50.f, 10.f);
		m_ground->CreateFixture(&groundShape, 0.f);
		
		b2BodyDef triangleDef;
		triangleDef.type = b2_dynamicBody;
		triangleDef.position.Set(0.f, 4.f);
		m_triangle = m_world.CreateBody(&triangleDef);
		b2PolygonShape triangleShape;
		triangleShape.SetAsBox(1.f, 1.f);
		b2FixtureDef triangleFixtureDef;
		triangleFixtureDef.shape = &triangleShape;
		triangleFixtureDef.density = 1.f;
		triangleFixtureDef.friction = 0.3f;
		m_triangle->CreateFixture(&triangleFixtureDef);
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

		sf::sleep(sf::seconds(PHYSICS_TIMESTEP));
		m_world.Step(PHYSICS_TIMESTEP, PHYSICS_VELOCITY_ITERATIONS, PHYSICS_POSITION_ITERATIONS);
		b2Vec2 position = m_triangle->GetPosition();
		float32 angle = m_triangle->GetAngle();
		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
			
		return true;
	}
};

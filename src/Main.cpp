#include <SFML/Graphics.hpp>

#include "State/PlayState.h"
#include "Particle/Particle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ChemBox");

	PlayState playState;
	State *state = &playState;
	state->init();

	/*Particle particle(sf::Vector2f(100, 100));
	particle.init();*/

	while(window.isOpen())
	{
		sf::Event event;
		if(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			state->tick(event);
		}
		/*window.clear();
		particle.update();
		particle.render(window);
		window.display();*/
		state->render(window);
	}

	return 0;
}
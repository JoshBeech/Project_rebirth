#include "Visualisation.h"
#include "StateHandler.h"

int main()
{
	//Git Welcome
	sf::RenderWindow window(sf::VideoMode(1024, 512), "Project Rebirth");

	SSTATEHANDLER.Intialise_states();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//World update and render here
		SSTATEHANDLER.UpdateCurrentState(SSTATEHANDLER.GetCurrentState());
		SSTATEHANDLER.RenderCurrentState(SSTATEHANDLER.GetCurrentState(), window);

	}

	delete &SVIZ;
	delete &SSTATEHANDLER;

	return 0;
}
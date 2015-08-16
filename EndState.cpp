#include "EndState.h"
#include "StateHandler.h"


EndState::EndState()
{
}


EndState::~EndState()
{
}

void EndState::OnEntry()
{
	//Anything when entering this state but not creating it.
	arial_font.loadFromFile("Media/Fonts/arial.ttf");
	text.setFont(arial_font);
	text.setString("Welcome to the exit menu :)");

	m_entering = false;
}

void EndState::OnExit()
{
	//When leaving this state but not destroying it
	m_entering = true;
}

void EndState::OnUpdate()
{
	if (m_entering)
	{
		OnEntry();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		SSTATEHANDLER.SetCurrentState(SSTATEHANDLER.MENU_STATE);
	}
}

void EndState::OnRender(sf::RenderWindow& window)
{
	//Test
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Blue);
	//shape.setPosition(100.f, 100.f);

	window.clear();
	SVIZ.RenderSprite("Background", window);
	window.draw(text);
	//window.draw(shape);
	window.display();
}
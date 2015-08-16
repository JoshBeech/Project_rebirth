#include "MenuState.h"
#include "StateHandler.h"

MenuState::MenuState()
{
	SVIZ.CreateSprite("Media/Arena_background_2.png", "Background");
}


MenuState::~MenuState()
{
}

void MenuState::OnEntry()
{
	//Anything when entering this state but not creating it.
	arial_font.loadFromFile("Media/Fonts/arial.ttf");
	text.setFont(arial_font);
	text.setString("Welcome to the main menu :)");

	m_entering = false;
}

void MenuState::OnExit()
{
	//When leaving this state but not destroying it
	m_entering = true;
}

void MenuState::OnUpdate()
{
	if (m_entering)
	{
		OnEntry();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		SSTATEHANDLER.SetCurrentState(SSTATEHANDLER.END_STATE);
	}
}

void MenuState::OnRender(sf::RenderWindow& window)
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

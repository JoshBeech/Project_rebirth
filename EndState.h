#pragma once
#include "IGameState.h"

class EndState : public IGameState
{
public:
	EndState();
	~EndState();
	void OnEntry();
	void OnExit();
	void OnUpdate();
	void OnRender(sf::RenderWindow& window);
private:
	bool m_entering = true;
	sf::Text text;
	sf::Font arial_font;

};


#pragma once
#include "Visualisation.h"
#include <memory>


class IGameState
{
public:
	//IGameSate();
	//~IGameSate();

	virtual void OnEntry() = 0;
	virtual void OnExit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender(sf::RenderWindow& window) = 0;

};
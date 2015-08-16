#pragma once

#include <iostream>
#include <memory>
#include "SFML\Graphics.hpp"

class MenuState;
//class MainGameState;
class EndState;

class StateHandler
{
public:
	static StateHandler& Get_instance();

	~StateHandler();

	enum States{ MENU_STATE = 1, MAIN_STATE, END_STATE };
	
	void Intialise_states();

	void UpdateCurrentState(const int current_state);
	void RenderCurrentState(const int current_state, sf::RenderWindow& window);
	
	void SetCurrentState(const int new_state);
	States GetCurrentState() { return m_current_state; }
protected:
	StateHandler();


private:
	static StateHandler* m_instance;
	
	States m_current_state = MENU_STATE;

	std::unique_ptr<MenuState> m_menu_state;
	//std::unique_ptr<MainGameState> m_main_game_state;
	std::unique_ptr<EndState> m_end_state;

};

#define SSTATEHANDLER StateHandler::Get_instance()

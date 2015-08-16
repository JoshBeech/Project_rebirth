#include "StateHandler.h"
#include "MenuState.h"
#include "EndState.h"

StateHandler* StateHandler::m_instance = NULL;

StateHandler& StateHandler::Get_instance()
{
	if (m_instance == NULL)
	{
		m_instance = new StateHandler;
	}

	return*m_instance;
}

StateHandler::StateHandler()
{
}

StateHandler::~StateHandler()
{
}

void StateHandler::Intialise_states()
{
	std::unique_ptr<MenuState> temp_menu(new MenuState());
	m_menu_state = std::move(temp_menu);

	//std::unique_ptr<MainGameState> temp_main(new MainGameState());
	//m_main_game_state = std::move(temp_main);

	std::unique_ptr<EndState> temp_end(new EndState());
	m_end_state = std::move(temp_end);

}

void StateHandler::UpdateCurrentState(const int current_state)
{
	//current state is WORLD enum
	switch (current_state)
	{
	case 1:
		//Update menu_state
		m_menu_state.get()->OnUpdate();
		break;
	case 2:
		//m_main_game_state.get()->On_update();
		break;
	case 3:
		//Update end_state
		m_end_state.get()->OnUpdate();
		break;
	default:
		break;
	}
}

void StateHandler::RenderCurrentState(const int current_state, sf::RenderWindow& window)
{
	switch (current_state)
	{
	case 1:
		//Render menu_state
		m_menu_state.get()->OnRender(window);
		break;
	case 2:
		//m_main_game_state.get()->On_render();
		break;
	case 3:
		//Render end_state
		m_end_state.get()->OnRender(window);
		break;
	default:
		break;
	}
}

void StateHandler::SetCurrentState(const int new_state)
{
	m_current_state = (States)new_state;
}
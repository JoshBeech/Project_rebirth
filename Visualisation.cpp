#include "Visualisation.h"

Visualisation* Visualisation::m_instance = nullptr;

Visualisation& Visualisation::GetInstance()
{
	if (nullptr == m_instance)
	{
		m_instance = new Visualisation;
	}
	return* m_instance;
}

Visualisation::Visualisation()
{
}

Visualisation::~Visualisation()
{
	for (auto s : m_sprite_map)
		delete s.second;

	for (auto t : m_texture_map)
		delete t.second;
}

void Visualisation::CreateSprite(const std::string& filename, const std::string& sprite_name)
{
	//Process of making sprite with sfml, requires texture for sprite.
	//Sprites are then added to a map
	
	sf::Texture* new_texture;
	new_texture = new sf::Texture;
	new_texture->loadFromFile(filename);
	m_texture_map[sprite_name] = new_texture;

	sf::Sprite* new_sprite = new sf::Sprite();
	new_sprite->setTexture(*new_texture);
	m_sprite_map[sprite_name] = new_sprite;
}

//Renders any sprite in map
//Improvements: Could overload to pass a list or vector of sprites to save multiple calls
void Visualisation::RenderSprite(const std::string& sprite_name, sf::RenderWindow& window)
{
	//int bob = m_texture_map.size();
	window.draw(*(m_sprite_map[sprite_name]));

	//return *(m_sprite_map[sprite_name]);
}

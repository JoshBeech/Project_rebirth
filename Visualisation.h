#pragma once

#include <SFML\Graphics.hpp>
#include <string.h>
#include <map>
#include <memory>

class Visualisation
{
public:
	static Visualisation& GetInstance();
	
	~Visualisation();

	void CreateWindow();
	void CreateSprite(const std::string& filename, const std::string& sprite_name);
	void RenderSprite(const std::string& sprite_name, sf::RenderWindow& window);

protected:
	Visualisation();

private:
	static Visualisation* m_instance;

	std::map<std::string, sf::Texture*> m_texture_map;
	std::map<std::string, sf::Sprite*> m_sprite_map;
};

#define SVIZ Visualisation::GetInstance()


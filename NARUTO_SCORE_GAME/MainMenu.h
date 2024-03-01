#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#define Max_main_menu 4
class MainMenu
{
public:
	MainMenu(float width, float height);
	
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int MainMenuPressed()
	{
		return MainMenuSelected;
	}
	~MainMenu();

private:
	sf::Text mainMenu[Max_main_menu];
	int MainMenuSelected;
	sf::Texture* texture;
	sf::Font font;
};
#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("Fonts/TokyoRockstar.ttf"))
	{
		std::cout << "No font";
	}

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("Play Game");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(800, 300);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Options");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(800, 400);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("About");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(800,500);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color::White);
	mainMenu[3].setString("Exit Game");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(800, 600);

	MainMenuSelected = -1;

	texture = new sf::Texture;
}

MainMenu::~MainMenu()
{
	if (texture != nullptr)
	{
		delete texture;
		texture = nullptr;
	}
}

void MainMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; ++i)
	{
		window.draw(mainMenu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);

		--MainMenuSelected;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected == 2;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Red);
	}

}

void MainMenu::MoveDown()
{
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);

		++MainMenuSelected;
		if (MainMenuSelected == 4)
		{
			MainMenuSelected == 0;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Red);
	}

}
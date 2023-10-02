#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>
#include "Weapon.h"
#include "Player.h"
#include "MainMenu.h"
#include "Enemy.h"

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Naruto_SCORE", sf::Style::Default);

	sf::Texture texture_back;
	texture_back.loadFromFile("Textures/background.png");
	sf::Sprite sprite_back(texture_back);

	MainMenu mainMenu(window.getSize().x, window.getSize().y);
	sf::Clock clock;
	Player player;
	std::vector<Enemy> enemies;
	player.kunaiList.clear();
	float enemySpawnInterval = 5.0f;
	sf::Clock enemySpawnTimer;

	sf::Music music;
	music.openFromFile("09. Battle Victory.mp3");
	music.setVolume(10);
	music.play();

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Key::Escape)
				{
					window.close();
					break;
				}
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					sf::RenderWindow PLAY(sf::VideoMode::getDesktopMode(), "NARUTO", sf::Style::Default);
					sf::RenderWindow OPTIONS(sf::VideoMode::getDesktopMode(), "Options", sf::Style::Default);
					sf::RenderWindow ABOUT(sf::VideoMode::getDesktopMode(), "About", sf::Style::Default);

					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						while (PLAY.isOpen())
						{
							sf::Event aevent;
							while (PLAY.pollEvent(aevent))
							{
								const float DeltaTime = clock.restart().asSeconds();
								if (aevent.type == sf::Event::Closed)
								{
									PLAY.close();
								}
								if (aevent.type == sf::Event::KeyPressed)
								{
									if (aevent.key.code == sf::Keyboard::Escape)
									{
										PLAY.close();

									}
								}
								window.close();
								OPTIONS.close();
								ABOUT.close();

								for (auto it = player.kunaiList.begin(); it != player.kunaiList.end();)
								{
									Kunai& kunai = *it;

									for (auto enemyIt = enemies.begin(); enemyIt != enemies.end();)
									{
										Enemy& enemy = *enemyIt;

										if (kunai.checkCollision(enemy.getSprite()))
										{
											it = player.kunaiList.erase(it);
											enemyIt = enemies.erase(enemyIt);
											player.incrementScore();
											kunai.setScored(true);
											continue;
										}
										else
										{
											++enemyIt;
										}
									}

									if (it != player.kunaiList.end())
									{
										++it;
									}
								}
								if (!player.isDead())
								{
									for (auto& enemy : enemies)
									{
										if (player.getBoundingBox().intersects(enemy.getSprite().getGlobalBounds()))
										{
											player.die();
										}
									}
								}

								PLAY.draw(sprite_back);

								for (Kunai& kunai : player.kunaiList)
								{
									kunai.update();
									PLAY.draw(kunai.getSprite());
								}

								sf::Text scoreText;
								sf::Font score;
								score.loadFromFile("Fonts/TokyoRockstar.ttf");
								scoreText.setFont(score);
								scoreText.setCharacterSize(50);
								scoreText.setFillColor(sf::Color::White);
								scoreText.setPosition(900.0f, 20.0f);
								scoreText.setString("Score: " + std::to_string(player.getScore()));
								PLAY.draw(scoreText);

								for (Enemy& enemy : enemies)
								{
									enemy.update(DeltaTime);
									if (!enemy.isDead())
									{
										PLAY.draw(enemy.getSprite());
									}
								}
								if (enemySpawnTimer.getElapsedTime().asSeconds() >= enemySpawnInterval)
								{
									enemySpawnTimer.restart();
									Enemy newEnemy;
									bool spawnOnLeft = rand() % 2 == 0;
									if (spawnOnLeft)
									{
										newEnemy.resetLeft(); 
									}
									else
									{
										newEnemy.resetRight();
									}

									enemies.push_back(newEnemy);
								}


								player.update(DeltaTime);


								if (!player.isDead())
								{
									player.draw(&PLAY);
								}

								if (player.isDead())
								{
									sf::Text gameOverText;
									sf::Font font;
									font.loadFromFile("Fonts/TokyoRockstar.ttf");
									gameOverText.setFont(font);
									gameOverText.setCharacterSize(128);
									gameOverText.setFillColor(sf::Color::Red);
									gameOverText.setString("Game Over");
									gameOverText.setPosition(730, 350);
									PLAY.clear();
									PLAY.draw(scoreText);
									PLAY.draw(gameOverText);
								}
								PLAY.display();
							}
						}
					}
					if (x == 1)
					{
						while (OPTIONS.isOpen())
						{
							sf::Event aevent;
							while (OPTIONS.pollEvent(aevent))
							{
								if (aevent.type == sf::Event::Closed)
								{
									OPTIONS.close();
								}
								if (aevent.type == sf::Event::KeyPressed)
								{
									if (aevent.key.code == sf::Keyboard::Escape)
									{
										OPTIONS.close();
									}
								}
								PLAY.close();
								ABOUT.close();
								OPTIONS.clear();

								OPTIONS.display();
							}
						}
					}
					if (x == 2)
					{
						while (ABOUT.isOpen())
						{
							sf::Event aevent;
							while (ABOUT.pollEvent(aevent))
							{
								if (aevent.type == sf::Event::Closed)
								{
									ABOUT.close();
								}
								if (aevent.type == sf::Event::KeyPressed)
								{
									if (aevent.key.code == sf::Keyboard::Escape)
									{
										ABOUT.close();
									}
								}
								PLAY.close();
								OPTIONS.clear();
								ABOUT.clear();
								ABOUT.display();
							}
						}
					}
					if (x == 3)
					{
						window.close();
						break;
					}
				}
			}
			window.clear();
			window.draw(sprite_back);
			mainMenu.draw(window);
			window.display();
		}
	}
	return 0;

}

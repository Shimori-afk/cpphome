#pragma once
#include <SFML/Graphics.hpp>
#include "Weapon.h"

enum class Direction { Left, Right };

class Player
{
public:
	Player();
	void incrementScore();
	void update(float DeltaTime);
	void draw(sf::RenderWindow* PLAY);
	sf::Vector2f getPosition() const;
	int getScore() const;
	std::vector<Kunai> kunaiList;
	sf::FloatRect getBoundingBox() const;  
	bool isDead() const; 
	void die(); 
	~Player();

	
private:
	
	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;
	sf::Vector2f m_velocity;
	bool m_isJumping;
	Direction m_direction;
	sf::Clock kunaiCooldownClock;
	const float kunaiCooldownTime = 0.5f;
	int score;
	bool dead;
};

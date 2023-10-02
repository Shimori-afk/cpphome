#include "Enemy.h"
#include <cstdlib>
#include <iostream>
Enemy::Enemy()
{
	enemyTexture.loadFromFile("Textures/enemy.png");
	enemySprite.setTexture(enemyTexture);
	enemySprite.setScale(sf::Vector2f(2.0f, 2.0f));
}

void Enemy::update(float DeltaTime)
{
	constexpr float MoveSpeedPerSecond = 200.0f;
	float MoveDelta = MoveSpeedPerSecond * DeltaTime;

	if (moveLeft)
	{
		enemySprite.move(MoveDelta, 0.0f);
	}
	else
	{
		enemySprite.move(-MoveDelta, 0.0f);
	}

	dead = false;
}

void Enemy::die()
{
	dead = true;
}

bool Enemy::isDead() const
{
	return dead;
}

sf::Sprite Enemy::getSprite()
{
	return enemySprite;
}

void Enemy::resetLeft()
{
	dead = false;

	enemySprite.setPosition(sf::Vector2f(-30.0f, 600.0f));
	moveLeft = true;
}

void Enemy::resetRight()
{
	dead = false;

	enemySprite.setPosition(sf::Vector2f(1900.0f, 600.0f));
	moveLeft = false;
}

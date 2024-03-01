#include "Player.h"
#include "Weapon.h"


Player::Player() : dead(false)
{
	m_playerTexture.loadFromFile("Textures/naruto_sprite.png");
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setScale(sf::Vector2f(0.35f, 0.35f));
	m_playerSprite.setPosition(sf::Vector2f(1030, 720));
	m_velocity = sf::Vector2f(0, 0);
	m_isJumping = false;
	score = 0;

}
void Player::incrementScore()
{
	score += 1; 
}

sf::Vector2f Player::getPosition() const
{
	return m_playerSprite.getPosition();
}

void Player :: draw(sf::RenderWindow* PLAY)
{
	PLAY->draw(m_playerSprite);

	for (auto& kunai : kunaiList)
	{
		PLAY->draw(kunai.getSprite());
	}
	
}

void Player::update(float DeltaTime)
{
	constexpr float MoveSpeedPerSecond = 200.0f;
	float MoveDelta = MoveSpeedPerSecond * DeltaTime;
	float jumpHeight = -30.0f;
	float gravity = 2.8f;

	sf::Vector2f position = m_playerSprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_direction = Direction::Right;
		position.x += MoveDelta;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_direction = Direction::Left;
		position.x -= MoveDelta;
	}

	if (m_direction == Direction::Right)
	{
		m_playerSprite.setScale(sf::Vector2f(-0.3f, 0.3f));
	}
	else
	{
		m_playerSprite.setScale(sf::Vector2f(0.3f, 0.3f));
	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (!m_isJumping)
		{
			m_velocity.y = jumpHeight;
			m_isJumping = true;
		}
	}

	m_velocity.y += gravity;
	position.y += m_velocity.y;

	if (position.y >= 630)
	{
		position.y = 630;
		m_velocity.y = 0;
		m_isJumping = false;
	}
	m_playerSprite.setPosition(position);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		if (kunaiCooldownClock.getElapsedTime().asSeconds() >= kunaiCooldownTime)
		{
			Kunai newKunai("left", getPosition());
			newKunai.getSprite().setPosition(getPosition());
			kunaiList.push_back(newKunai);

			kunaiCooldownClock.restart();
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		if (kunaiCooldownClock.getElapsedTime().asSeconds() >= kunaiCooldownTime)
		{
			Kunai newKunai("right", getPosition());
			newKunai.getSprite().setPosition(getPosition());
			kunaiList.push_back(newKunai);

			kunaiCooldownClock.restart();
		}
	}

	for (auto& kunai : kunaiList)
	{
		kunai.update();
	}

	kunaiList.erase(std::remove_if(kunaiList.begin(), kunaiList.end(), [](Kunai& kunai)
		{ return kunai.isOutOfBounds(); }), kunaiList.end());

}

sf::FloatRect Player::getBoundingBox() const
{
	return m_playerSprite.getGlobalBounds();
}

bool Player::isDead() const
{
	return dead;
}

void Player::die()
{
	dead = true;
}

Player::~Player()
{

}

int Player::getScore() const
{
	return score;
}

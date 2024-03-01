#include "Weapon.h"


Kunai::Kunai(const std::string& direction, sf::Vector2f startPosition)
{
    
    kunaiTexture.loadFromFile("Textures/kunai.png");
    kunaiSprite.setTexture(kunaiTexture);
    kunaiSprite.setScale(sf::Vector2f(0.07f, 0.07f));
    kunaiSprite.setPosition(startPosition);
    if (direction == "left")
    {
        velocity = sf::Vector2f(-5.0f, 0.0f); 
    }
    else if (direction == "right") 
    {
        velocity = sf::Vector2f(5.0f, 0.0f); 
       
    }
    scored = false;
}

void Kunai::update()
{
 
    kunaiSprite.move(velocity);
}

bool Kunai::isOutOfBounds() 
{
    sf::Vector2f position = kunaiSprite.getPosition();
    return position.x > 1920 || position.x < 0 || position.y > 1080 || position.y < 0;
}


sf::Sprite Kunai::getSprite()
{
    return kunaiSprite;
}

bool Kunai::checkCollision(const sf::Sprite& enemySprite)
{
    sf::FloatRect kunaiBounds = kunaiSprite.getGlobalBounds();
    sf::FloatRect enemyBounds = enemySprite.getGlobalBounds();
    return kunaiBounds.intersects(enemyBounds);
}

bool Kunai::hasScored() const
{
    return scored;
}

void Kunai::setScored(bool scored)
{
    this->scored = scored;
}

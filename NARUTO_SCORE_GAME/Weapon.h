#pragma once
#include <SFML/Graphics.hpp>

class Kunai {
public:
    Kunai(const std::string& direction, sf::Vector2f startPosition);
    void update();
    bool isOutOfBounds();
    sf::Sprite getSprite();
    bool checkCollision(const sf::Sprite& enemySprite);
    bool hasScored() const; 
    void setScored(bool scored);

private:
    sf::Texture kunaiTexture;
    sf::Sprite kunaiSprite;
    sf::Vector2f velocity;
    bool scored;
};

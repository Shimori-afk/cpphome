#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
 
    Enemy();
    void update(float DeltaTime);
    void die();
    void resetLeft();
    void resetRight();
    bool isDead() const;
    sf::Sprite getSprite();

private:
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    bool dead;
    bool moveLeft;

};
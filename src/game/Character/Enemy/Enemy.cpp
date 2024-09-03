#include "Enemy.h"

#include <iostream>

Enemy::Enemy(int xx, int yy, sf::Texture& textura, int offX, int offY) :
Character(xx, yy, offX, offY, 2,  textura),
nivelMaldade(1)
{
}

Enemy::~Enemy() {}
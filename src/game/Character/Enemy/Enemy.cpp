#include "Enemy.h"

Enemy::Enemy() :
nivelMaldade(1)
{

}

Enemy::~Enemy() {}

void Enemy::drawTestEnemy(Renderer& renderer) {
    float groundY = 492; // Talvez usar um getGround() pra não deixar hardcoded
    shape.setSize(sf::Vector2f(50.0f, 100.0f));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(300.0f, 200.0f);
    shape.setPosition(shape.getPosition().x, groundY - shape.getSize().y / 2);
    renderer.addDrawable(shape);
}

void Enemy::executar()
{
}

#include "Enemy.h"

#include <iostream>

Enemy::Enemy() :
nivelMaldade(1)
{

}

Enemy::~Enemy() {}

void Enemy::inimigoTeste(Renderer& renderer) {
    float groundY = 492; // Talvez usar um getGround() pra não deixar hardcoded
    shape.setSize(sf::Vector2f(50.0f, 100.0f));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(300.0f, groundY - shape.getSize().y / 2);
    renderer.addDrawable(shape);
}

bool indoDireita = true;
void Enemy::mover(float deltaTime) {

}

void Enemy::executar(float deltaTime)
{
    this->mover(deltaTime);
}

void Enemy::danificar(Player* jogador)
{
    jogador->setVida(jogador->getVida() - nivelMaldade);
}

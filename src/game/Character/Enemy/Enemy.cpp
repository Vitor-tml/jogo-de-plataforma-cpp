#include "Enemy.h"

#include <iostream>

Enemy::Enemy(sf::Texture& textura) :
nivelMaldade(1),
Character(100, 100, 20, textura),
estaNoChao(false),
fisica(),
posXInicial(sprite.getPosition().x),
limiteDireita(posXInicial + distancia),
limiteEsquerda(posXInicial - distancia)
{
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setScale(sf::Vector2f(3.f, 3.f));
    sprite.setOrigin(sf::Vector2f(16, 16));
    sprite.setPosition(x, y);
}

Enemy::~Enemy() {}

void Enemy::mover(float deltaTime) {
    posXInicial = sprite.getPosition().x;

    if (indoDireita) {
        sprite.move(velocidadeHorizontal * deltaTime, 0.0f);
        if (sprite.getPosition().x >= limiteDireita) {
            indoDireita = false;
        }
    } else {
        sprite.move(-velocidadeHorizontal * deltaTime, 0.0f);
        if (sprite.getPosition().x <= limiteEsquerda) {
            indoDireita = true;
        }
    }
}

void Enemy::executar(float deltaTime)
{
    fisica.aplicaFisica(sprite, velocidade, deltaTime, estaNoChao);
    this->mover(deltaTime);
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;
}

void Enemy::danificar(Player* jogador)
{
    jogador->setVida(jogador->getVida() - nivelMaldade);
}

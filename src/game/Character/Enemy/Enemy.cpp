#include "Enemy.h"

#include <iostream>

Enemy::Enemy(sf::Texture& textura) :
nivelMaldade(1),
Character(100, 100, 20, textura),
estaNoChao(false),
fisica()
{
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setScale(sf::Vector2f(3.f, 3.f));
    sprite.setOrigin(sf::Vector2f(16, 16));
    sprite.setPosition(x, y);
}

Enemy::~Enemy() {}

bool indoDireita = true;
void Enemy::mover(float deltaTime) {
    static float velocidadeHorizontal = 100.0f; // Pixels por segundo
    static float distancia = 200.0f; // Distância total do movimento
    static float posXInicial = sprite.getPosition().x;

    float limiteDireita = posXInicial + distancia;
    float limiteEsquerda = posXInicial - distancia;

    if (indoDireita) {
        velocidadeHorizontal += 200.0f;
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

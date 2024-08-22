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
    static float velocidadeHorizontal = 100.0f; // Pixels por segundo
    static float distancia = 200.0f; // Distância total do movimento
    static float posXInicial = shape.getPosition().x;

    float limiteDireita = posXInicial + distancia;
    float limiteEsquerda = posXInicial - distancia;

    if (indoDireita) {
        velocidadeHorizontal += 200.0f;
        shape.move(velocidadeHorizontal * deltaTime, 0.0f);
        if (shape.getPosition().x >= limiteDireita) {
            indoDireita = false;
        }
    } else {
        shape.move(-velocidadeHorizontal * deltaTime, 0.0f);
        if (shape.getPosition().x <= limiteEsquerda) {
            indoDireita = true;
        }
    }
}

void Enemy::executar(float deltaTime)
{
    this->mover(deltaTime);
}

void Enemy::danificar(Player* jogador)
{
    jogador->setVida(jogador->getVida() - nivelMaldade);
}

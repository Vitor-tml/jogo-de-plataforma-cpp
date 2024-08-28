#include "Enemy.h"

#include <iostream>

Enemy::Enemy(sf::Texture& textura) :
velocidadeHorizontal(100.f),
distancia(200.f),
indoDireita(true),
nivelMaldade(1),
Character(100, 100, 0, 0, 20, textura),
estaNoChao(false),
posXInicial(sprite.getPosition().x),
limiteDireita(posXInicial + distancia),
limiteEsquerda(posXInicial - distancia)
{
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 96, 144));
    sf::FloatRect tamanho = sprite.getGlobalBounds();
    sprite.setOrigin(sf::Vector2f(tamanho.width/2, tamanho.height)); // Centro da sprite
    sprite.setPosition(x, y);
    inicializarCaixaColisao();
}

Enemy::~Enemy() {}

void Enemy::mover(float deltaTime) {
    if (indoDireita) {
        // sprite.move(velocidadeHorizontal * deltaTime, 0.0f);
        this->setVelocidade(getVelocidade() + sf::Vector2f(velocidadeHorizontal * deltaTime, 0.f));
        if (x >= limiteDireita) {
            indoDireita = false;
        }
    } else {
        this->setVelocidade(getVelocidade() + sf::Vector2f(-velocidadeHorizontal * deltaTime, 0.f));
        // sprite.move(-velocidadeHorizontal * deltaTime, 0.0f);
        if (x <= limiteEsquerda) {
            indoDireita = true;
        }
    }
}

void Enemy::executar(float deltaTime)
{
    this->mover(deltaTime);
    fisica.aplicaFisica(sprite, velocidade, deltaTime, estaNoChao);
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;

    atualizarCaixaColisao();
}

void Enemy::danificar(Player* jogador)
{
    jogador->setVida(jogador->getVida() - nivelMaldade);
}

int Enemy::getVida() const {
    return nVidas;
}

nlohmann::json Enemy::salvar() const {
    nlohmann::json j;
    j["id"] = getID();
    j["posX"] = getPosicao().x;
    j["posY"] = getPosicao().y;
    j["health"] = getVida();
    return j;
}

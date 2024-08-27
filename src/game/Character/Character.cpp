#include "Character.h"

void Character::setVelocidade(const sf::Vector2f& novaVelocidade) {
    this->velocidade = novaVelocidade;
}

sf::Vector2f Character::getVelocidade() const {
    return this->velocidade;
}


void Character::setNoChao(bool noChao)
{
    estaNoChao = noChao;
}

bool Character::getNoChao() const
{
    return estaNoChao;
}

void Character::setPosicao(int xx, int yy)
{
    sprite.setPosition(xx, yy);
}
void Character::setPosicao(sf::Vector2f posicao)
{
    sprite.setPosition(posicao);
}
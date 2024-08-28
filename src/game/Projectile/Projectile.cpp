#include "Projectile.h"

Projetctile::Projetctile(int xx, int yy, sf::Texture &textura, int offsetX, int offsetY):
    Entity(xx, yy, offsetX, offsetY, textura),
    empuxo(true),
    velocidadeHorizontal(10.f)
{
    sprite.setPosition(x, y);
}

void Projetctile::executar(float deltaTime)
{
    estaNoChao = (estaNoChao && empuxo); // Caso tenha empuxo, não está no chão
    velocidade.x = velocidadeHorizontal; //mudar para parametro
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;
    fisica.aplicaFisica(sprite, velocidade, deltaTime, estaNoChao);
}
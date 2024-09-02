#include "Projetil.h"


Projetil::Projetil(int xx, int yy, int offsetX, int offsetY):
    Entity(xx, yy, offsetX, offsetY, gRecursos->getTexture("bala")),
    empuxo(true),
    velocidadeHorizontal(10.f)
{
    sprite.setPosition(x, y);
    inicializarCaixaColisao();
}

void Projetil::executar(float deltaTime)
{
    estaNoChao = (estaNoChao && empuxo); // Caso tenha empuxo, não está no chão
    velocidade.x = velocidadeHorizontal; //mudar para parametro
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;
    fisica.aplicaFisica(sprite, velocidade, deltaTime, estaNoChao);
    atualizarCaixaColisao();
}

void Projetil::danificar(Player *jogador)
{
    jogador->operator--();

}
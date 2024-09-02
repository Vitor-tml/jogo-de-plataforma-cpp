#include "Projetil.h"


Projetil::Projetil(int xx, int yy, int offsetX, int offsetY):
    Entity(xx, yy, offsetX, offsetY, gRecursos->getTexture("bala")),
    empuxo(true),
    velocidadeHorizontal(10.f)
{
    setNoChao(true);
    sprite.setPosition(x, y);
    sf::FloatRect tamanho = sprite.getGlobalBounds();
    sprite.setOrigin(sf::Vector2f(tamanho.width/2, tamanho.height)); // Centro da sprite
    inicializarCaixaColisao();
}

void Projetil::executar(float deltaTime)
{
    atualizarCaixaColisao();
    estaNoChao = (estaNoChao && empuxo); // Caso tenha empuxo, não está no chão
    velocidade.x = velocidadeHorizontal; //mudar para parametro
    if(velocidade.x > 0)
        sprite.setScale(-1, 1);
    else
        sprite.setScale(1, 1);

    x = sprite.getPosition().x;
    y = sprite.getPosition().y;
    fisica.aplicaFisica(sprite, velocidade, deltaTime, estaNoChao);
}

void Projetil::danificar(Player *jogador)
{
    jogador->operator--();

}

void Projetil::setVelocidade(float speed)
{
    velocidadeHorizontal = speed;
}

float Projetil::getVelocidade() const
{
    return velocidadeHorizontal;
}
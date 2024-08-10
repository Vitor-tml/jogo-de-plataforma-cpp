#include "Player.h"
Player::Player(sf::Texture& textura)
    :  estaNoChao(false),
       fisica(), // Mudar os valores padroes para cada entidade
       parado(textura, {sf::IntRect(0, 0, 32, 32),
                        sf::IntRect(32, 0, 32, 32), 
                        sf::IntRect(64, 0, 32, 32), 
                        sf::IntRect(96, 0, 32, 32)},
                        0.3f),
       andando(textura, {sf::IntRect(0, 64, 32, 32), 
                         sf::IntRect(32, 64, 32, 32), 
                         sf::IntRect(64, 64, 32, 32), 
                         sf::IntRect(96, 64, 32, 32),
                         sf::IntRect(128, 64, 32, 32),
                         sf::IntRect(160, 64, 32, 32),
                         sf::IntRect(192, 64, 32, 32),
                         sf::IntRect(224, 64, 32, 32)},
                        0.1f),
       animacaoAtual(&parado)
{   
    // Define animações
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setScale(sf::Vector2f(3.f, 3.f));
    sprite.setOrigin(sf::Vector2f(16, 16));
    sprite.setPosition(100, 100);
}

void Player::update(float deltaTime)
{
    userInput();
    fisica.aplicaFisica(sprite, velocidade, deltaTime, estaNoChao);

    // Atualiza animaçaão atual
    animacaoAtual->update(deltaTime);
    sprite.setTextureRect(animacaoAtual->getFrameAtual());

}

void Player::userInput()
{
    // Zera velocidade horizontal para não ter aceleração infinita
    velocidade.x = 0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        velocidade.x -= velocidadeHorizontal;
        sprite.setScale(sf::Vector2f(-3 , 3));
        animacaoAtual = &andando;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        velocidade.x += velocidadeHorizontal;
        sprite.setScale(sf::Vector2f(3 , 3));
        animacaoAtual = &andando;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && estaNoChao){
        velocidade.y += -fisica.getPulo();
        estaNoChao = false;
    }

    if(velocidade.x == 0)
    {
        animacaoAtual = &parado;
    }
}

sf::Sprite& Player::getSprite()
{
    return sprite;
}
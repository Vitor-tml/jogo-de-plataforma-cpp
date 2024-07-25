#include "Player.h"
Player::Player(const sf::Texture& textura)
    :  estaNoChao(false),
       fisica() // Mudar os valores padroes para cada entidade
{   
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setScale(sf::Vector2f(2.f, 2.f));
    sprite.setPosition(100, 100);
}
void Player::update(float deltaTime)
{
    userInput();
    fisica.aplicaFisica(sprite, velocidade, deltaTime, estaNoChao);

}
void Player::userInput()
{
    velocidade.x = 0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        velocidade.x -= velocidadeHorizontal;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        velocidade.x += velocidadeHorizontal;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && estaNoChao){
        velocidade.y += -fisica.getPulo();
        estaNoChao = false;
    }

}
sf::Sprite& Player::getSprite()
{
    return sprite;
}
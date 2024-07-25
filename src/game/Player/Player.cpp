#include "Player.h"

Player::Player(const sf::Texture& textura)
    :  estaNoChao(false)
{   
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setScale(sf::Vector2f(2.f, 2.f));
    sprite.setPosition(100, 100);
}
void Player::update(float deltaTime)
{
    userInput();
    applyPhysics(deltaTime);

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
        velocidade.y += -alturaPulo;
        estaNoChao = false;
    }

}
void Player::applyPhysics(float deltaTime)
{
    velocidade.y += gravidade * deltaTime;

    sprite.move(velocidade * deltaTime);

    if(sprite.getPosition().y >= 500){
        sprite.setPosition(sprite.getPosition().x , 500);
        velocidade.y = 0;
        estaNoChao = true;
    }
}
sf::Sprite& Player::getSprite()
{
    return sprite;
}
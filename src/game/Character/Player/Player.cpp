#include "Player.h"
// Sprite real -> 40x58
Player::Player(sf::Texture& textura)
:   Character(100, 100, 56, 28, 20, textura), // Definindo vida do player
    estaNoChao(false),
    fisica(), // Mudar os valores padrões para cada entidade
    parado(textura, {sf::IntRect(0, 0, 96, 96),
                     sf::IntRect(96, 0, 96, 96), 
                     sf::IntRect(192, 0, 96, 96), 
                     sf::IntRect(288, 0, 96, 96)},
                    0.3f),
    andando(textura, {sf::IntRect(0, 192, 96, 96), 
                      sf::IntRect(96, 192, 96, 96), 
                      sf::IntRect(192, 192, 96, 96), 
                      sf::IntRect(288, 192, 96, 96),
                      sf::IntRect(384, 192, 96, 96),
                      sf::IntRect(480, 192, 96, 96),
                      sf::IntRect(576, 192, 96, 96),
                      sf::IntRect(672, 192, 96, 96)},
                    0.1f),
    animacaoAtual(&parado)
{   
    // Define animações
    sprite.setTextureRect(sf::IntRect(0, 0, 96, 96));
    sf::FloatRect tamanho = sprite.getGlobalBounds();
    sprite.setOrigin(sf::Vector2f(tamanho.width/2, tamanho.height)); // Centro da sprite
    sprite.setPosition(x, y);

    inicializarCaixaColisao(40, 58); // Tamanho real da sprite
}

void Player::executar(float deltaTime)
{
    userInput();
    fisica.aplicaFisica(sprite, velocidade, deltaTime, estaNoChao);
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;

    atualizarCaixaColisao();

    // Atualiza animação atual
    animacaoAtual->update(deltaTime);
    sprite.setTextureRect(animacaoAtual->getFrameAtual());
}

void Player::userInput()
{
    // Zera velocidade horizontal para não ter aceleração infinita
    velocidade.x = 0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        velocidade.x -= velocidadeHorizontal;
        sprite.setScale(sf::Vector2f(-1 , 1)); ///< Muda a direção da sprite
        animacaoAtual = &andando;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        velocidade.x += velocidadeHorizontal;
        sprite.setScale(sf::Vector2f(1 , 1)); ///< Muda a direção da sprite
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

int Player::getVida(){
    return nVidas;
}

void Player::setVida(int vida){
    this->nVidas = vida;
}

sf::Sprite& Player::getSprite()
{
    return sprite;
}

#include "Player.h"
// Sprite real -> 40x58
Player::Player(sf::Texture& textura)
:   Character(100, 100, 56, 28, 20, textura), // Definindo vida do player
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
    animacaoAtual(&parado),
    pontos(0)
{   
    // Define animações
    sprite.setTextureRect(sf::IntRect(0, 0, 96, 96));
    sf::FloatRect tamanho = sprite.getGlobalBounds();
    sprite.setOrigin(sf::Vector2f(tamanho.width/2, tamanho.height)); // Centro da sprite
    sprite.setPosition(x, y);
    coracao.setTexture(gRecursos->getTexture("coracao"));
    inicializarCaixaColisao(40, 58); // Tamanho real da sprite
}

void Player::executar(float deltaTime)
{
    userInput();
    verificarLimitesTela();
    // std::cout << nVidas << std::endl;
    fisica.aplicaFisica(sprite, velocidade, deltaTime, estaNoChao);
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;

    atualizarCaixaColisao();

    // Atualiza animação atual
    animacaoAtual->update(deltaTime);
    sprite.setTextureRect(animacaoAtual->getFrameAtual());
    renderizaVida();
}

void Player::userInput()
{
    // std::cout << "Player 1" << std::endl;

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

int Player::getVida() const {
    return nVidas;
}

void Player::setVida(int vida){
    this->nVidas = vida;
}

sf::Sprite& Player::getSprite()
{
    return sprite;
}

nlohmann::json Player::salvar() const {
    nlohmann::json j;
    j["id"] = getID();
    j["posX"] = getPosicao().x;
    j["posY"] = getPosicao().y;
    j["health"] = getVida();
    return j;
}

void Player::renderizaVida()
{
    sf::RenderTexture vidas;
    sf::FloatRect cTamanho = coracao.getGlobalBounds();    

    vidas.create(cTamanho.width * nVidas, cTamanho.height);

    for(int i = 0; i < nVidas; i++)
    {
        coracao.setPosition(cTamanho.width * i, 0);
        vidas.draw(coracao);
    }
    vidas.display();
    sf::Sprite* coracoes = new sf::Sprite(vidas.getTexture());
    gGrafico->addDrawable(coracoes, 4);
}

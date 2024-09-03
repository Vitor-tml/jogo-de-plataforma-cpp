
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
    rolando(textura, {sf::IntRect(0, 480, 96, 96), 
                      sf::IntRect(96, 480, 96, 96), 
                      sf::IntRect(192, 480, 96, 96), 
                      sf::IntRect(288, 480, 96, 96),
                      sf::IntRect(384, 480, 96, 96),
                      sf::IntRect(480, 480, 96, 96),
                      sf::IntRect(576, 480, 96, 96),
                      sf::IntRect(672, 480, 96, 96)},
                    0.1f),
    animacaoAtual(&parado),
    pontos(100)
{   
    // Define animações
    sprite.setTextureRect(sf::IntRect(0, 0, 96, 96));
    sf::FloatRect tamanho = sprite.getGlobalBounds();
    sprite.setOrigin(sf::Vector2f(tamanho.width/2, tamanho.height)); // Centro da sprite
    sprite.setPosition(x, y);
    vida.setFont(gRecursos->getFont("fonte"));
    vida.setFillColor(sf::Color::White);
    vida.setCharacterSize(20);
    inicializarCaixaColisao(40, 58); // Tamanho real da sprite
    setExecutar(true);
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

    if (ataque)
    {
        tempoAtaque += deltaTime;
        if (tempoAtaque >= duracaoAtaque)
        {
            ataque = false; // Sai do estado de ataque
            animacaoAtual = &parado; // Retorna à animação padrão
        }
    }

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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        atacar();
    }

    if(velocidade.x == 0 && !ataque)
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

    std::string aux = "Player 1: " + std::to_string(nVidas);
    vida.setString(aux);
    vida.setPosition(0, 0);
    gGrafico->addDrawable(vida, 4);
}

void Player::atacar()
{
    animacaoAtual = &rolando;
    ataque = true;
    tempoAtaque = 0.f; // Reinicia o tempo do ataque
    sf::Vector2f speed = getVelocidade();
    setVelocidade(sf::Vector2f(speed.x * 2, speed.y));
}

bool Player::getAtaque() const {
    return ataque;
}
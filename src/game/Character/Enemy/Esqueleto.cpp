#include "Esqueleto.h"

Esqueleto::Esqueleto( int maldade, int offX, int offY) :
Enemy(100, 100, gRecursos->getTexture("esqueleto"), offX, offY),
velocidadeHorizontal(100.f),
distancia(200.f),
indoDireita(true),
estaNoChao(false),
posXInicial(sprite.getPosition().x),
limiteDireita(posXInicial + distancia),
limiteEsquerda(posXInicial - distancia)
{
    sprite.setTextureRect(sf::IntRect(5, 0, 42, 72));
    sf::FloatRect tamanho = sprite.getGlobalBounds();
    sprite.setOrigin(sf::Vector2f(tamanho.width/2, tamanho.height)); // Centro da sprite
    sprite.setPosition(x, y);
    inicializarCaixaColisao();
}

Esqueleto::~Esqueleto() {}

void Esqueleto::mover(float deltaTime) {

    sf::Vector2f speed = this->getVelocidade();
    sf::Vector2f aceleracao(velocidadeHorizontal * deltaTime, 0.0f);
    sf::FloatRect hitBox = caixaColisao.getGlobalBounds();
    sf::Vector2 tela = gGrafico->getTamanho();

    if(indoDireita)
        indoDireita = (x >= limiteDireita || hitBox.left + hitBox.width >= tela.x)? false : true;
    else
        indoDireita = (x <= limiteEsquerda || hitBox.left - hitBox.width <= 300)? true : false;

    if(indoDireita){
        this->setVelocidade(speed + aceleracao);
    }else{
        this->setVelocidade(speed - aceleracao);
    }
    
    // if (indoDireita) {
    //     // sprite.move(velocidadeHorizontal * deltaTime, 0.0f);
    //     this->setVelocidade(getVelocidade() + sf::Vector2f(velocidadeHorizontal * deltaTime, 0.f));
    //     if (x >= limiteDireita || x >=  gGrafico->getTamanho().x) {
    //         indoDireita = false;
    //     }
    // } else {
    //     this->setVelocidade(getVelocidade() + sf::Vector2f(-velocidadeHorizontal * deltaTime, 0.f));
    //     // sprite.move(-velocidadeHorizontal * deltaTime, 0.0f);
    //     if (x <= limiteEsquerda || x - caixaColisao.getGlobalBounds().width <= 0) {
    //         indoDireita = true;
    //     }
    // }
}

void Esqueleto::executar(float deltaTime)
{
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;
    this->mover(deltaTime);
    verificarLimitesTela();
    fisica.aplicaFisica(sprite, velocidade, deltaTime, estaNoChao);
    // std::cout << "Vida esqueleto: " << getVida() << std::endl;
    atualizarCaixaColisao();
}


void Esqueleto::danificar(Player* jogador)
{
    // Verifica se o tempo entre danos já passou
    if (relogioDano.getElapsedTime().asSeconds() >= tempoEntreDanos) {
        jogador->setVida(jogador->getVida() - nivelMaldade);
        relogioDano.restart(); // Reinicia o relógio após infligir dano
    }
}

nlohmann::json Esqueleto::salvar() const{
    nlohmann::json j;
    j["id"] = getID();
    j["posX"] = getPosicao().x;
    j["posY"] = getPosicao().y;
    j["health"] = getVida();
    return j;
}

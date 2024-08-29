#include "Esqueleto.h"

Esqueleto::Esqueleto(sf::Texture& textura, int maldade, int offX, int offY) :
Enemy(100, 100, textura, offX, offY),
velocidadeHorizontal(100.f),
distancia(200.f),
indoDireita(true),
estaNoChao(false),
posXInicial(sprite.getPosition().x),
limiteDireita(posXInicial + distancia),
limiteEsquerda(posXInicial - distancia)
{
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 96, 144));
    sf::FloatRect tamanho = sprite.getGlobalBounds();
    sprite.setOrigin(sf::Vector2f(tamanho.width/2, tamanho.height)); // Centro da sprite
    sprite.setPosition(x, y);
    inicializarCaixaColisao();
}

Esqueleto::~Esqueleto() {}

void Esqueleto::mover(float deltaTime) {
    if (indoDireita) {
        // sprite.move(velocidadeHorizontal * deltaTime, 0.0f);
        this->setVelocidade(getVelocidade() + sf::Vector2f(velocidadeHorizontal * deltaTime, 0.f));
        if (x >= limiteDireita) {
            indoDireita = false;
        }
    } else {
        this->setVelocidade(getVelocidade() + sf::Vector2f(-velocidadeHorizontal * deltaTime, 0.f));
        // sprite.move(-velocidadeHorizontal * deltaTime, 0.0f);
        if (x <= limiteEsquerda) {
            indoDireita = true;
        }
    }
}

void Esqueleto::executar(float deltaTime)
{
    this->mover(deltaTime);
    fisica.aplicaFisica(sprite, velocidade, deltaTime, estaNoChao);
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;

    atualizarCaixaColisao();
}

void Esqueleto::danificar(Player* jogador)
{
    jogador->setVida(jogador->getVida() - nivelMaldade);
}

nlohmann::json Esqueleto::salvar() const{
    nlohmann::json j;
    j["id"] = getID();
    j["posX"] = getPosicao().x;
    j["posY"] = getPosicao().y;
    j["health"] = getVida();
    return j;
}

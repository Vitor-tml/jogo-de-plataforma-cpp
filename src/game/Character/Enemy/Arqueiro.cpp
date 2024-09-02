#include "Arqueiro.h"

Arqueiro::Arqueiro(int xx, int yy, sf::Texture& textura):
Enemy(xx, yy, textura, 0, 0)
{
    tempoDecorrido = 0;
    tempoDecorridoTiro = 0;
    sprite.setTextureRect(sf::IntRect(0, 0, 125, 75));
    sf::FloatRect tamanho = sprite.getGlobalBounds();
    sprite.setOrigin(sf::Vector2f(tamanho.width/2, tamanho.height)); // Centro da sprite
    sprite.setPosition(x, y);
    inicializarCaixaColisao();
}


void Arqueiro::mover(float deltaTime) {
    // Atualiza o tempo decorrido
    tempoDecorrido += deltaTime;

    // Verifica se é hora de mudar a direção
    if (tempoDecorrido >= intervaloTroca) {
        olhandoDireita = !olhandoDireita; // Troca a direção
        tempoDecorrido = 0.0f;            // Reseta o tempo decorrido
    }

    // Define a escala do sprite com base na direção
    if (olhandoDireita) {
        sprite.setScale(1.f, 1.f);  // Olhando para a direita
    } else {
        sprite.setScale(-1.f, 1.f); // Olhando para a esquerda
    }
}

nlohmann::json Arqueiro::salvar() const {
    nlohmann::json data;
    data["olhandoDireita"] = olhandoDireita;
    data["nBalas"] = nBalas;
    // Salvar outras informações relevantes
    return data;
}

void Arqueiro::danificar(Player *jogador)
{
    jogador->operator--();
}

void Arqueiro::executar(float deltaTime)
{
    mover(deltaTime);
    atirar(deltaTime);
    if(nBalas > 0)
    {

    }
    fisica.aplicaFisica(sprite, velocidade, deltaTime, estaNoChao);
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;
    atualizarCaixaColisao();

    //atirar
}

void Arqueiro::atirar(float deltaTime)
{
    tempoDecorridoTiro += deltaTime;
    Projetil* bala;
    if (tempoDecorridoTiro >= intervaloTiro) {
        tempoDecorridoTiro = 0.0f;            // Reseta o tempo decorrido
        if (olhandoDireita) {
            bala = new Projetil(x, y);
        } else {
            std::cout << "Esquerda" << std::endl;
            bala = new Projetil(x, y);
            // adicionar bala aqui
        }
    }
    // Define a escala do sprite com base na direção
}
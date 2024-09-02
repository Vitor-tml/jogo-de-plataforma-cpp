#ifndef _ESQUELETO_H
#define _ESQUELETO_H

#include "Enemy.h"
#include "../../../lib/json.hpp"

class Esqueleto : public Enemy{
private:
    bool estaNoChao;

    bool indoDireita = true;              // Utilizado para movimentar o inimigo
    float posXInicial;
    const float velocidadeHorizontal;     // Pixels por segundo
    const float distancia;                // Distância total do movimento
    const float limiteDireita;
    const float limiteEsquerda;
    sf::Clock relogioDano; // Relógio para controlar o tempo entre danos
    const float tempoEntreDanos = 1.0f; // Tempo em segundos entre danos
public:
    Esqueleto(sf::Texture& textura, int maldade = 1, int offX = 0, int offY = 0);
    ~Esqueleto();
    void mover(float deltaTime);
    void executar(float deltaTime);                 // Transformar em virtual futuramente
    void danificar(Player* jogador);                // Transformar em virtual futuramente
    void executar() {}
    sf::Vector2f getPosicao() const { return sf::Vector2f(x, y);}
    nlohmann::json salvar() const override;
    int getVida() const { return nVidas; };
};
#endif
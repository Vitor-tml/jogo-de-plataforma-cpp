#ifndef _ENEMY_H
#define _ENEMY_H

#include <SFML/Graphics.hpp>
#include "../Character.h"
#include "../Player/Player.h"


class Enemy : public Character {
private:
    PhysicsComponent fisica;
    bool estaNoChao;
    sf::Vector2f velocidade;

    bool indoDireita = true;                       // Utilizado para movimentar o inimigo
    float posXInicial;
    const float velocidadeHorizontal = 100.0f;     // Pixels por segundo
    const float distancia = 200.0f;                // Distância total do movimento
    const float limiteDireita;
    const float limiteEsquerda;

protected:
    int nivelMaldade;

public:
    Enemy(sf::Texture& textura);
    ~Enemy();                                       // Transformar em virtual futuramente

    void mover(float deltaTime);
    void executar(float deltaTime);                 // Transformar em virtual futuramente
    void danificar(Player* jogador);                // Transformar em virtual futuramente
    void executar() {}
    void salvar() {}

};
#endif
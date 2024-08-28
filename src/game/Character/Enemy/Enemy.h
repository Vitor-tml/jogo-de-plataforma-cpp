#ifndef _ENEMY_H
#define _ENEMY_H

#include "../../../lib/json.hpp"
#include <SFML/Graphics.hpp>
#include "../Character.h"
#include "../Player/Player.h"


class Enemy : public Character {
private:
    bool estaNoChao;

    bool indoDireita = true;                       // Utilizado para movimentar o inimigo
    float posXInicial;
    const float velocidadeHorizontal;     // Pixels por segundo
    const float distancia;                // Distância total do movimento
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
    int getVida() const;
    sf::Vector2f getPosicao() const { return sf::Vector2f(x, y);}
    nlohmann::json salvar() const override;
};
#endif
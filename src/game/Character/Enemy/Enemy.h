#ifndef _ENEMY_H
#define _ENEMY_H

#include <SFML/Graphics.hpp>
#include "../Character.h"
#include "../Player/Player.h"


class Enemy : public Character {
private:
    sf::RectangleShape shape;                   // Para o teste

protected:
    int nivelMaldade;

public:
    Enemy();
    ~Enemy();                                   // Transformar em virtual futuramente

    void inimigoTeste(Renderer& renderer);
    void mover(float deltaTime);
    void executar(float deltaTime);              // Transformar em virtual futuramente
    void danificar(Player* jogador);            // Transformar em virtual futuramente
    void executar() {}
    void salvar() {}
};
#endif
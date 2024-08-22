#ifndef _ENEMY_H
#define _ENEMY_H

#include <SFML/Graphics.hpp>
#include "../Character.h"
#include "../../../engine/Renderer/Renderer.h"
#include "../../../engine/PhysicsComponent/PhysicsComponent.h"

class Player;
class Enemy {
private:
    sf::RectangleShape shape;                   // Para o teste

protected:
    int nivelMaldade;

public:
    Enemy();
    ~Enemy();                                   // Transformar em virtual futuramente

    void drawTestEnemy(Renderer& renderer);
    void executar();                            // Transformar em virtual futuramente
    void danificar(Player* jogador);            // Transformar em virtual futuramente
};
#endif
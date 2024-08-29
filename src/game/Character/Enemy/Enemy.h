#ifndef _ENEMY_H
#define _ENEMY_H

#include "../../../lib/json.hpp"
#include <SFML/Graphics.hpp>
#include "../Character.h"
#include "../Player/Player.h"


class Enemy : public Character {
protected:
    int nivelMaldade;
public:
    Enemy(int xx, int yy, sf::Texture& textura, int offX = 0, int offY = 0);
    ~Enemy();                                       // Transformar em virtual futuramente

    virtual void mover(float deltaTime) = 0;
    virtual void executar(float deltaTime) = 0;                 // Transformar em virtual futuramente
    virtual void danificar(Player* jogador) = 0;                // Transformar em virtual futuramente
    virtual void executar() = 0;
    virtual nlohmann::json salvar() const = 0;
};
#endif
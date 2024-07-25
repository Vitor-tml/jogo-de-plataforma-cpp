#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>
#include "../../engine/PhysicsComponent/PhysicsComponent.h"

class Player {
private:
    sf::Sprite sprite;
    sf::Vector2f velocidade;
    bool estaNoChao;
    PhysicsComponent fisica;
    // Constantes de movimento
    const float velocidadeHorizontal = 200.f;
public:
    Player(const sf::Texture& textura);
    void update(float deltaTime);
    void userInput();
    sf::Sprite& getSprite();
};
#endif
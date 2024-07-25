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
    const float alturaPulo = 300.f; // Mudar depois para velocidade
    const float gravidade = 980.f;    
public:
    Player(const sf::Texture& textura);
    void update(float deltaTime);
    void userInput();
    void applyPhysics(float deltaTime);
    sf::Sprite& getSprite();
};
#endif
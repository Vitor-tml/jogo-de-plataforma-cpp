#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>
#include "../../engine/PhysicsComponent/PhysicsComponent.h"
#include "../../engine/Animation/Animation.h"
#include <map>

/**
 * @class Player
 * @brief A classe que representa o jogador dentro do programa
 * 
 * A classe player encapsula a lógica de controle, física e animação do personagem principal do jogo
 * 
 * @author Vitor-tml
 */
class Player {
private:
    sf::Sprite sprite;
    // Constantes de movimento
    PhysicsComponent fisica;
    bool estaNoChao;
    const float velocidadeHorizontal = 200.f;
    sf::Vector2f velocidade;

    // Animação
    Animation parado; // 0 0
    Animation andando;// 0 68
    Animation *animacaoAtual;
    void setAnimation(const std::string& name);

public:
    // tinha um const antes de texture, testar se isso muda algo depois
    Player(sf::Texture& textura);
    void update(float deltaTime);
    void userInput();
    sf::Sprite& getSprite();
};
#endif
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
    /**
     * @brief "Desenho" na tela, que representa o jogador,
     */
    sf::Sprite sprite;
    /**
     * @brief Componente que controla a física do player
     * @see PhysicsComponent
     */
    PhysicsComponent fisica;
    bool estaNoChao;
    const float velocidadeHorizontal = 200.f;
    /**
     * Velocidade vertical e horizontal do player.
     */
    sf::Vector2f velocidade;
    /**
     * @brief Componente que controlam o estado atual da sprite do player, gerando a animação.
     * @see Animation
     */
    Animation parado; // 0 0
    Animation andando;// 0 68
    Animation *animacaoAtual;
    /**
     * @brief Muda o estado atual da animação do player
     * @param name nome definido para a animação (hard code)
     */
    void setAnimation(const std::string& name);

public:
    /**
     * @brief construtora do player, carrega o spritesheet do personagem.
     * @todo Valor padrão para ser também uma construtora sem parâmetros
     */
    Player(sf::Texture& textura);
    /**
     * @brief Atualiza o estado da animação e le a entrada do usuário
     * @param deltaTime Tempo decorrido entra a ultima chamada da função
     * @todo Testar implementação por evento, em vez de deltaTiem
     */
    void update(float deltaTime);
    /**
     * @brief Atualiza animação e estado do player de acordo com a entrada do usuário, responsável pela movimentação do personagem.
     */
    void userInput();
    /**
     * @brief Retorna sprite atual do player
     * @return Estado atual da animação/player para renderização
     */
    sf::Sprite& getSprite();
};
#endif